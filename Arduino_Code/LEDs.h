#ifndef LEDS_H
#define LEDS_H

#include "config.h"

// Initializes Status LEDs
void initStatLEDs();        

// Turns on specified LED                   
void turnOnLED(int ledNumber);  

// Turns off specified LED
void turnOffLED(int ledNumber);                

#endif