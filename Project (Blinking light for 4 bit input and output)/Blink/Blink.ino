/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
/*
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
*/
// Output LED's Pin.
int D4=13; //D4=O3
int D3=12; //D3=O2
int D2=11; //D2=O1
int D1=10; //D1=O0

//Input pin.

int I3=3;
int I2=2;
int I1=1;
int I0=0;

// Temporary Storage.
int I3_val=0;
int I2_val=0;
int I1_val=0;
int I0_val=0;


void setup(){
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);

  pinMode(I3, INPUT);
  pinMode(I2, INPUT);
  pinMode(I1, INPUT);
  pinMode(I0, INPUT); 
}

void loop(){
boolean  I3_val=digitalRead(I3);
boolean  I2_val=digitalRead(I2);
boolean  I1_val=digitalRead(I1);
boolean  I0_val=digitalRead(I0);

boolean D4_val;
boolean D3_val;
boolean D2_val;
boolean D1_val;




D4_val=((!I0_val&!I1_val&!I2_val)|(!I0_val&!I1_val&I3_val)|(I1_val&!I2_val&I3_val)|(I1_val&I2_val&!I3_val)|(I0_val&!I1_val&I2_val));

D3_val=((!I0_val&!I1_val&!I3_val)|(I0_val&!I2_val&I3_val)|(!I0_val&I1_val&I2_val&I3_val));

D2_val=((!I0_val&I3_val)|(I2_val&I3_val)|(I0_val&I1_val&!I2_val));

D1_val=((!I0_val&!I1_val)|(!I1_val&!I2_val&!I3_val)|(!I0_val&!I2_val&I3_val)|(!I1_val&I2_val&I3_val)|(I0_val&I1_val&!I3_val));
 

  digitalWrite(D1,D1_val); 
  digitalWrite(D2,D2_val); 
  digitalWrite(D3,D3_val); 
  digitalWrite(D4,D4_val); 

}
