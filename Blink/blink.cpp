/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  This example code is in the public domain, as far as I know.
 */

#include <avr/Arduino.h>

int main() {
  // run Arduino initialization script for setting delay vectors and timing
  //    variables
  init();

  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);

  // actual loop for blinking the led each second
  while( 1 ){
    digitalWrite(13, HIGH);   // set the LED on
    delay(1000);              // wait for a second
    digitalWrite(13, LOW);    // set the LED off
    delay(1000);              // wait for a second
  }

  // complete
  return 0;
} // end int main()
