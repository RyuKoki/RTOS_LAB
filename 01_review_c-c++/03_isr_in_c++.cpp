/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

int interrupt_channel = 0;
int output_pin = 5;
int state = 0;

void setup() {
  pinMode(output_pin, OUTPUT); // define output pin
  // define and create INTERRUPT at ISR_BLINK
  // using External Interrupt 0 >> INT0
  // using CHANGE mode >> detect interrupt both RISING & FALLING Edge
  attachInterrupt(interrupt_channel, ISR_BLINK, CHANGE);
}

void loop() {
  // Serial.println(state);
  // show up output
  digitalWrite(output_pin, state);
}

void ISR_BLINK() {
  // Serial.println(state);
  // toggle output
  state = !state;
}
