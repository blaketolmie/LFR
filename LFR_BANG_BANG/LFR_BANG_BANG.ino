#include "config.h"
#include "Motors.h"
#include "LEDs.h"
#include "Sensors.h"
/* Hold down reset switch to stop motors */ 

// Motor values
int16_t threshold = 100;        // Threshold for bang bang controller
int16_t speed_up = 150;         // Motor speed fast
int16_t slow_down = 100;        // Motor speed slow
int16_t forward = 150;          // Motor speed when forward

void setup() {
    Serial.begin(9600);
    initStatLEDs();
    initMotors();
    initSensors();
}

void loop() {
    int16_t sensor_1 = analogRead(SENSOR_1);
    int16_t sensor_2 = analogRead(SENSOR_2);
    int16_t sensor_3 = analogRead(SENSOR_3);
    int16_t sensor_4 = analogRead(SENSOR_4);
    // If adding a 5th sensor make it so then middle sensor just means it goes straight

    // Convert ADC values to digital values. Group the sensors into left and right
    int16_t leftSensors = (sensor_1 < threshold) || (sensor_2 < threshold);
    int16_t rightSensors = (sensor_3 < threshold) || (sensor_4 < threshold);

    // Bang bang controller. Reminder that setMotorSpeed(int16_t leftSpeed, int16_t rightSpeed)
    if (leftSensors && !rightSensors) {
        // If the left group sense the line, turn left by increasing speed of right motor etc
        setMotorSpeed(slow_down,speed_up);
        turnOnLED(LED_1);
        turnOffLED(LED_2);
        turnOffLED(LED_3);
        
    } else if (rightSensors && !leftSensors) {
        // If the right group sense the line, turn right by increasing speed of left motor etc
        setMotorSpeed(speed_up,slow_down);
        turnOnLED(LED_2);
        turnOffLED(LED_1);
        turnOffLED(LED_3);
    } else {
        // Else move forward
        setMotorSpeed(forward,forward);
        turnOnLED(LED_3);
        turnOffLED(LED_1);
        turnOffLED(LED_2);
    }

    delay(500);     // Delay for 0.5 seconds (for stability) - reduce to 0.1 seconds after removing serial communication println's
}