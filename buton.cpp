#include "buton.h"

buton::buton(int pin)
{
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

int buton::apasare()
{
    int buttonState = digitalRead(pin);
    if (buttonState == HIGH)
    {
        return 1;
    }
    else
        return 0;
}
