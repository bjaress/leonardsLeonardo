#include <Console.h>
#include <ctype.h>

const unsigned int time_unit = 100;

void
setup ()
{
    // initialize the digital pin as an output.
    // Pin 13 has an LED connected on most Arduino boards:
    pinMode (13, OUTPUT);

    Bridge.begin();
    Console.begin();
    while (!Console);
}


/* Read characters, blink them in Morse code, then echo them back.  */
void
loop ()
{
    if (Console.available() <= 0) return;
    char c = Console.read();

    blink(c);

    Console.print(c);
}

/* Low-level blink based on fixed time units.  */
void
blink(int on_units, int off_units)
{
    if (on_units > 0) {
        digitalWrite (13, HIGH);
        delay (on_units * time_unit);
    }
    digitalWrite (13, LOW);
    delay (off_units * time_unit);
}

/*
 * For ease of implementation, dots and dashes come with the slight
 * pause required between them, and gaps will be added on cumulatively.
 */
void dot() { blink(1, 1); }
void dash() { blink(3, 1); }
void gap() { blink(0, 2); }

/*
 * Mid-level blink taking a string of dots and dashes for one character
 */
void
blink(const char * encoding)
{
    while (*encoding) {
        switch (*encoding++) {
            case '-' : dash();
            break;
            case '.' : dot();
            break;
        }
    }
    gap();  //extend final inter-dot gap into an inter-letter gap
}


/*
 * High-level blink taking English characters.
 */
void
blink (char symbol)
{
    symbol = (char)tolower(symbol);
    switch (symbol) {
        case  'a':   blink(".-");       break;
        case  'b':   blink("-...");     break;
        case  'c':   blink("-.-.");     break;
        case  'd':   blink("-..");      break;
        case  'e':   blink(".");        break;
        case  'f':   blink("..-.");     break;
        case  'g':   blink("--.");      break;
        case  'h':   blink("....");     break;
        case  'i':   blink("..");       break;
        case  'j':   blink(".---");     break;
        case  'k':   blink("-.-");      break;
        case  'l':   blink(".-..");     break;
        case  'm':   blink("--");       break;
        case  'n':   blink("-.");       break;
        case  'o':   blink("---");      break;
        case  'p':   blink(".--.");     break;
        case  'q':   blink("--.-");     break;
        case  'r':   blink(".-.");      break;
        case  's':   blink("...");      break;
        case  't':   blink("-");        break;
        case  'u':   blink("..-");      break;
        case  'v':   blink("...-");     break;
        case  'w':   blink(".--");      break;
        case  'x':   blink("-..-");     break;
        case  'y':   blink("-.--");     break;
        case  'z':   blink("--..");     break;
        case  '0':   blink("-----");    break;
        case  '1':   blink(".----");    break;
        case  '2':   blink("..---");    break;
        case  '3':   blink("...--");    break;
        case  '4':   blink("....-");    break;
        case  '5':   blink(".....");    break;
        case  '6':   blink("-....");    break;
        case  '7':   blink("--...");    break;
        case  '8':   blink("---..");    break;
        case  '9':   blink("----.");    break;
        case  '.':   blink(".-.-.-");   break;
        case  ',':   blink("--..--");   break;
        case  '?':   blink("..--..");   break;
        case  '\'':  blink(".----.");   break;
        case  '!':   blink("-.-.--");   break;
        case  '/':   blink("-..-.");    break;
        case  '(':   blink("-.--.");    break;
        case  ')':   blink("-.--.-");   break;
        case  '&':   blink(".-...");    break;
        case  ':':   blink("---...");   break;
        case  ';':   blink("-.-.-.");   break;
        case  '=':   blink("-...-");    break;
        case  '+':   blink(".-.-.");    break;
        case  '-':   blink("-....-");   break;
        case  '_':   blink("..--.-");   break;
        case  '"':   blink(".-..-.");   break;
        case  '$':   blink("...-..-");  break;
        case  '@':   blink(".--.-.");   break;



        //Extend the gap to a seven-unit inter-word gap
        case ' ': gap(); break;
    }
}
