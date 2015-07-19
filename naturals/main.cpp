/*
 * Flash the sequence 1, 2, 3, ...
 */

#include <Arduino.h>

void flash (unsigned int count);

int
main (void)
{
    setup ();

    for (unsigned int count = 0;; count++)
      {
          flash (count);
          delay (500);
      }

    return 0;
}

void
setup ()
{
    init ();
#if defined(USBCON)
    USBDevice.attach();
#endif
    // initialize the digital pin as an output.
    // Pin 13 has an LED connected on most Arduino boards:
    pinMode (13, OUTPUT);
}

void
flash (unsigned int count)
{
    while (count--)
      {
          digitalWrite (13, HIGH);
          delay (500);
          digitalWrite (13, LOW);
          delay (500);
      }
}
