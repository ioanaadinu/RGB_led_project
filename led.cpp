#include "led.h"

led::led(int pinr, int ping, int pinb)
{
    this->pinr = pinr;
    this->ping = ping;
    this->pinb = pinb;
    pinMode(pinr, OUTPUT);
    pinMode(ping, OUTPUT);
    pinMode(pinb, OUTPUT);
}

void led::RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
    analogWrite(pinr, red_light_value);
    analogWrite(ping, green_light_value);
    analogWrite(pinb, blue_light_value);
}
