#ifndef ARDUINO_BUTON_H
#define ARDUINO_BUTON_H
#include <Arduino.h>

class buton
{
private:
	int pin;

public:
	buton(int);
	int apasare();
};
#endif
