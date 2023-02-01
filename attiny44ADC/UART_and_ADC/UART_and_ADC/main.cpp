/*
 * UART_and_ADC.cpp
 *
 * Created: 04-05-2021 22:57:09
 * Author : Naman Puri
 */ 

// DEFINE DIRECTIVES
#define F_CPU	1000000UL
#define BAUDRATE 1200
#define STOPBITS  1

// INCLUDE DIRECTIVES
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// variable definItions
enum USISERIAL_SEND_STATE { AVAILABLE, FIRST, SECOND };
static volatile enum USISERIAL_SEND_STATE usiserial_send_state = AVAILABLE;
static volatile uint8_t usiserial_tx_data;
uint8_t encodedValues[2];  //arr[0] will contain LSN, arr[1] will contain MSN

// function definitions
void encodeADC(uint8_t channelid, uint8_t adcval, uint8_t encodedvalues[]){
	uint8_t lower, upper = 0;
	lower = (adcval & 0x0F) | (channelid  << 4);
	upper = (adcval >> 4) | (0x80 | (channelid << 4));
	encodedvalues[0] = lower;
	encodedvalues[1] = upper;
}
static inline enum USISERIAL_SEND_STATE usiserial_send_get_state(void)
{
	return usiserial_send_state;
}

static inline void usiserial_send_set_state(enum USISERIAL_SEND_STATE state)
{
	usiserial_send_state=state;
}

bool usiserial_send_available()
{
	return usiserial_send_get_state()==AVAILABLE;
}

static inline uint8_t usiserial_get_tx_data(void)
{
	return usiserial_tx_data;
}

static inline void usiserial_set_tx_data(uint8_t tx_data)
{
	usiserial_tx_data = tx_data;
}

static uint8_t reverse_byte (uint8_t x) {
	x = ((x >> 1) & 0x55) | ((x << 1) & 0xaa);
	x = ((x >> 2) & 0x33) | ((x << 2) & 0xcc);
	x = ((x >> 4) & 0x0f) | ((x << 4) & 0xf0);
	return x;
}

void usiserial_send_byte(uint8_t data)
{
	while (usiserial_send_get_state() != AVAILABLE)
	{
		// Spin until we finish sending previous packet
	};
	usiserial_send_set_state(FIRST);
	usiserial_set_tx_data(reverse_byte(data));

	// Configure Timer0
	TCCR0A = (1 << WGM01);   // CTC mode
	TCCR0A &= (~((1 << WGM02) | (1 << WGM00)));
	TCCR0B = (1 << CS01);                   // Set prescaler to clk /8
	TCCR0B &= (~((1 << CS02) | (1 << CS00)));
	GTCCR = 1 << PSR10;                    // Reset prescaler
	OCR0A = 104;                            // Trigger every full bit width
	TCNT0 = 0;                              // Count up from 0

	// Configure USI to send high start bit and 7 bits of data
	USIDR = (0x00) |                            // Start bit (low)
	(usiserial_get_tx_data() >> 1);         // followed by first 7 bits of serial data
	
	USICR  = (1 << USIOIE)|                     // Enable USI Counter OVF interrupt.
	(0 << USIWM1) | (1 << USIWM0)|              // Select three wire mode to ensure USI written to PA5
	(0 << USICS1) | (1 << USICS0) | (0 << USICLK);  // Select Timer0 Compare match as USI Clock source.
	
	DDRA  |= (1 << PA5);                        // Configure USI_DO as output.
	
	USISR = (1 << USIOIF) |                       // Clear USI overflow interrupt flag
	(16 - 8);                             // and set USI counter to count 8 bits
}

// USI overflow interrupt indicates we have sent a buffer
ISR (USI_OVF_vect) {
	if (usiserial_send_get_state() == FIRST)
	{
		usiserial_send_set_state(SECOND);
		USIDR = (usiserial_get_tx_data() << 7)  // Send last 1 bit of data
		| (0x7F);                           // and stop bits (high)
		
		USISR = (1 << USIOIF) |                   // Clear USI overflow interrupt flag
		(16 - (1 + (STOPBITS)));          // Set USI counter to send last data bit and stop bits
	}
	else
	{
		PORTA |= (1 << PA5);                    // Ensure output is high
		DDRA  |= (1 << PA5);                    // Configure USI_DO as output.
		USICR = 0;                            // Disable USI.
		USISR |= (1 << USIOIF);                   // clear interrupt flag

		usiserial_send_set_state(AVAILABLE);
	}
}

void ADC_Init()
{
	DDRA &= (~((1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3)));			/* Make PA0,1,2,3 as INPUT */
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | ( 1<< ADPS0);			/* Enable ADC, fr/128  */
	ADMUX &= (~((1 << REFS1) | (1 << REFS0)));			                  /* Vref: vcc */	
}

int ADC_Read(uint8_t channel)
{
	uint8_t analogvalue = 0;
	
	ADMUX = (channel & 0x0F);	/* Set input channel to read */
	ADCSRB |= (1 << ADLAR);		/* left adjust the result */
	ADCSRA |= (1 << ADSC);		/* Start conversion */
	while((ADCSRA & (1 << ADIF)) == 0);	/* Monitor end of conversion interrupt */
	//_delay_us(10);
	analogvalue = ADCH;			/* read adc value*/
	return(analogvalue);			/* Return sampled value*/
}

uint8_t avg16(uint8_t pin){
	int value = 0;
	for(int j = 0; j < 16; j++){
		value += ADC_Read(pin);
	}
	value /= 16;
	return (uint8_t)value;
}
int main(void)
{
	DDRA  |= (1 << PA5);
	PORTA |= (1 << PA5); 
	sei();
	ADC_Init();
	
	//int r,g,b,i = 0;
    
    while (1) 
    {
		uint8_t r,g,b,i = 0;
	
		g = avg16(0x01);
		encodeADC(0x01,g,encodedValues);
		while (!usiserial_send_available())
		{// Wait for last send to complete
		}
		usiserial_send_byte(encodedValues[0]);
		while (!usiserial_send_available())
		{// Wait for last send to complete
		}
		usiserial_send_byte(encodedValues[1]);			
				
		b = avg16(0x02);
		encodeADC(0x02,b,encodedValues);
		while (!usiserial_send_available())
		{// Wait for last send to complete
		}
		usiserial_send_byte(encodedValues[0]);
		while (!usiserial_send_available())
		{// Wait for last send to complete
		}
		usiserial_send_byte(encodedValues[1]);

		i = avg16(0x03);
		encodeADC(0x03,i,encodedValues);
		while (!usiserial_send_available())
		{// Wait for last send to complete
		}
		usiserial_send_byte(encodedValues[0]);
		while (!usiserial_send_available())
		{// Wait for last send to complete
		}
		usiserial_send_byte(encodedValues[1]);    
		}
}

