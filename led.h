#ifndef ARDUINO_LED_H
#define ARDUINO_LED_H
#include <Arduino.h>

class led
{
private:
	int pinr;
	int ping;
	int pinb;

public:
	led(int, int, int);
	void RGB_color(int, int, int);
};
#endif
