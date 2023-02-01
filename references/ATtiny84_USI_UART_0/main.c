/**
 * @file MikrocontrollerUsiUart
 * module: main.c
 *
 *  @date Aug 3, 2017
 *  @author Alan Offt
 */
#include <avr/io.h>
#include <util/delay.h>
#include "USI_UART.h"

int main(void) {
	USI_UART_init();		// set up pin directions, flush buffers, etc
	char intro[] = "Hello Alan";		// quotes make it a string
	uint8_t i = 0;
	while (intro[i]) {		// a string null is equivalent to a FALSE condition
		USI_UART_Transmit_Byte(intro[i++]);
	}
	USI_UART_Transmit_Byte('\n');
	_delay_ms(2000);
	for(;;) {
		while(USI_UART_Data_In_Receive_Buffer()) {
			char received_byte = USI_UART_Receive_Byte();
//			_delay_ms(1);		// was part of the debugging process
			USI_UART_Transmit_Byte(received_byte);
		}
	}
}

