#include "LEDs.h"

// Initialize LED pins
void initStatLEDs() {
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    Serial.println("LEDs set to output");
}

// Turn on specified LED
void turnOnLED(int ledNumber) {
    digitalWrite(ledNumber, HIGH); 
    Serial.println("LED on");
}

// Turn off specified LED
void turnOffLED(int ledNumber) {
    digitalWrite(ledNumber, LOW); 
    Serial.println("LED off");
}

// Blink the LED
void blinkLED(,int ledNumber, int interval) {
    interval = interval * 1000;
    digitalWrite(ledNumber, HIGH);
    delay(interval);
    digitalWrite(ledNumber, LOW);
    delay(interval);
}