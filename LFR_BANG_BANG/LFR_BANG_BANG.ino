#include "config.h"
#include "Motors.h"
#include "LEDs.h"
#include "Sensors.h"
/* Hold down reset switch to stop motors */ 
/* If lights are flickering must manually start motors */

// Motor values
int16_t threshold = 230;        // Threshold for bang bang controller 200
int16_t speed_up = 70;         // Motor speed fast, 55 without weights, 80 good for rectangle with weights, 70 perfect for complex track

int16_t slow_down = 0;        // Motor speed slow
int16_t forward = 30;          // Motor speed when forward

int16_t left_speed = 65; // original 30 then 60
int16_t right_speed = 65;

// testing
// int16_t threshold1 = 230;        // Threshold for bang bang controller
// int16_t threshold5 = 230;


void setup() {
    // Serial.begin(9600);
    initStatLEDs();
    initMotors();
    initSensors();
}

void loop() {
    turnOnLED(LED_1);
    int16_t sensor_1 = analogRead(SENSOR_1);
    int16_t sensor_5 = analogRead(SENSOR_5);
    
    if (sensor_1 < threshold) {  // when on line
        // If the left group sense the line, turn left by increasing speed of right motor etc
        left_speed = speed_up;
        right_speed = slow_down;
    } else if (sensor_5 < threshold) {
        // If the right group sense the line, turn right by increasing speed of left motor etc
        left_speed = slow_down;
        right_speed = speed_up;
    }
    setMotorSpeed(left_speed,right_speed);
    // setMotorSpeed(0,speed_up);


    if (sensor_1 < threshold) {
      turnOnLED(LED_2);
    } else {
      turnOffLED(LED_2);
    }
    if (sensor_5 < threshold) {
      turnOnLED(LED_3);
    } else {
      turnOffLED(LED_3);
    }

}
