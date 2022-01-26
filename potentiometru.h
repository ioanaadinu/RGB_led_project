#ifndef ARDUINO_POTENTIOMETRU_H
#define ARDUINO_POTENTIOMETRU_H
#include <Arduino.h>

class potentiometru
{
private:
	int pin;

public:
	potentiometru(int);
	int valoare();
};
#endif
