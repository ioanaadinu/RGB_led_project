#ifndef ARDUINO_FOTOREZISTOR_H
#define ARDUINO_FOTOREZISTOR_H
#include <Arduino.h>

class fotorezistor
{
private:
	int pin;

public:
	fotorezistor(int);
	int lux();
};
#endif
