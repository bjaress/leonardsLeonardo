void flash (unsigned int count);

void
setup ()
{
    // initialize the digital pin as an output.
    // Pin 13 has an LED connected on most Arduino boards:
    pinMode (13, OUTPUT);
}

unsigned int flash_count = 0;
void loop () {
    flash(flash_count++);
    delay (500);
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
