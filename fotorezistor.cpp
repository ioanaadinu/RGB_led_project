#include "fotorezistor.h"

fotorezistor::fotorezistor(int pin)
{

   this->pin = pin;
   pinMode(this->pin, INPUT);
}

int fotorezistor::lux()
{
   int value1 = analogRead(pin);
   return value1;
}