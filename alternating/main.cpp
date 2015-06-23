/*
 * Simple alternating blink from the arduino-mk examples, but altered to
 * be a .cpp file including the main method and imports that are
 * automatically added to .ino files.
 */

#include <Arduino.h>

int main(void)
{
        init();

#if defined(USBCON)
        USBDevice.attach();
#endif

        setup();

        for (;;) {
                loop();
                if (serialEventRun) serialEventRun();
        }

        return 0;
}

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
}

void loop() {
  digitalWrite(13, HIGH);   // set the LED on
  delay(1000);              // wait a second
  digitalWrite(13, LOW);    // set the LED off
  delay(1000);              // wait for a second
}
