#define adc0  0 
#define adc1  1
#define adc2  2 
#define adc3  3
#define clk   4
#define out0  5
uint8_t laststate, currentstate = 1;
int adc0data;
char data0[10];
bool flag = true;
int j = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(adc0, INPUT);
  pinMode(adc1, INPUT);
  pinMode(adc2, INPUT);
  pinMode(adc3, INPUT);
  pinMode(clk, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag){
    adc0data = analogRead(adc0);
    itoa( adc0data, data0 , 2 );
    flag = false;
  }
  
  currentstate = digitalRead(clk);
  if(currentstate!=laststate){
    if(currentstate == 0){
      digitalWrite(out0, data0[j]);
      j++;
      if(j==10){
        j = 0;
        flag = true;
      }
    }
  }
  laststate = currentstate;
}
