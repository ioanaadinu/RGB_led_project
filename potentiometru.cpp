#include "potentiometru.h"

potentiometru::potentiometru(int pin)
{
    this->pin = pin;
    pinMode(this->pin, INPUT);
}
int potentiometru::valoare()
{
    int value = analogRead(pin);
    value = map(value, 0, 1023, 255, 0);
    return value;
}
