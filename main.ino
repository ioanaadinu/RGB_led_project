#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "fotorezistor.h"
#include "potentiometru.h"
#include "buton.h"
#include "led.h"
#define pResistor A0
#define potPin A1
#define buttonPin1 2
#define buttonPin2 3
#define red_light_pin 11
#define green_light_pin 10
#define blue_light_pin 9

fotorezistor fotorezist(pResistor);
potentiometru potent(potPin);
buton but1(buttonPin1);
buton but2(buttonPin2);
led rgb(red_light_pin, green_light_pin, blue_light_pin);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.begin();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("PROIECT");
}

int x = 0;
int y = 0;
int contorRGB = 1;
int R = 0;
int G = 0;
int B = 0;

void loop()
{
    if (but1.apasare() && !but2.apasare())
    {
        x = 1;
        y = 0;
    }

    if (x == 1)
    {
        rgb.RGB_color(0, 0, 0);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("=Senzor lumina==");
        lcd.setCursor(4, 1);
        lcd.print(fotorezist.lux());
        lcd.print(" lux");
        delay(500);
        if (potent.valoare() < 250)
        {
            x = 0;
            lcd.clear();
        }
    }

    if (but2.apasare() && !but1.apasare())
    {
        y = 1;
        x = 0;
    }
    if (y == 1)
    {
        if (contorRGB == 3)
        {

            lcd.setCursor(0, 0);
            lcd.print("====MOD RGB=====");
            lcd.setCursor(0, 1);
            lcd.setCursor(11, 1);
            lcd.print("B:");
            lcd.print(potent.valoare());
            lcd.print(" ");
            B = potent.valoare();
            rgb.RGB_color(R, G, B);
            delay(500);
            if (but2.apasare() && but1.apasare())
            {
                contorRGB = 5;
                y = 0;
            }
        }
        if (contorRGB == 2)
        {

            lcd.setCursor(0, 0);
            lcd.print("====MOD RGB=====");
            lcd.setCursor(0, 1);
            lcd.setCursor(5, 1);
            lcd.print("G:");
            lcd.print(potent.valoare());
            lcd.print(" ");
            G = potent.valoare();
            rgb.RGB_color(R, G, B);
            delay(500);
            if (but2.apasare() && but1.apasare())
            {
                contorRGB = 3;
                y = 0;
            }
        }
        if (contorRGB == 1)
        {
            lcd.setCursor(0, 0);
            lcd.print("====MOD RGB=====");
            lcd.setCursor(0, 1);
            lcd.print("R:");
            lcd.print(potent.valoare());
            lcd.print(" ");
            R = potent.valoare();
            rgb.RGB_color(R, G, B);
            delay(500);
            if (but1.apasare() && but2.apasare())
            {
                contorRGB = 2;
                y = 0;
            }
        }
    }
    if (contorRGB == 5)
    {
        contorRGB = 1;
    }
}
