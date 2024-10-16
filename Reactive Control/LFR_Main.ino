#include "config.h"
#include "Motors.h"
#include "LEDs.h"
#include "Sensors.h"

int16_t threshold = 230;      // Threshold for sensors on main course
int16_t speed_up = 70;        // Motor speeds
int16_t slow_down = 0;
int16_t forward = 30;
int16_t left_speed = 65;      // Starting motor speeds
int16_t right_speed = 65;

void setup() {
    initStatLEDs();
    initMotors();
    initSensors();
}

void loop() {
    // Read sensor values
    int16_t sensor_1 = analogRead(SENSOR_1);
    int16_t sensor_3 = analogRead(SENSOR_3);
    int16_t sensor_5 = analogRead(SENSOR_5);

    if (sensor_3 < threshold) {
      // Forward
        left_speed = (speed_up-10);
        right_speed = (speed_up-10);
    } else if (sensor_1 < threshold) {
        // If the left sensor senses the line, turn left by increasing speed of right motor etc
        left_speed = speed_up;
        right_speed = slow_down;
    } else if (sensor_5 < threshold) {
        // If the right sensor senses the line, turn right by increasing speed of left motor etc
        left_speed = slow_down;
        right_speed = speed_up;
    }

    setMotorSpeed(left_speed,right_speed);

    // LED sensor indicators
    if (sensor_1 < threshold) {   // sensor 1 sensing line
      turnOnLED(LED_1);
    } else {
      turnOffLED(LED_1);
    }
    if (sensor_3 < threshold) {   // sensor 3 sensing line
      turnOnLED(LED_2);
    } else {
      turnOffLED(LED_2);
    }
    if (sensor_5 < threshold) {   // sensor 5 sensing line
      turnOnLED(LED_3);
    } else {
      turnOffLED(LED_3);
    }
}
