#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// PID constants / tuning
#define float Kp = 2.0;  // Proportional constant
#define float Ki = 1.0;  // Integral constant
#define float Kd = 1.0;  // Derivative constant
#define int16_t INTEGRAL_LIMIT = 100; // Integral windup limit

// Key constraints
#define SETPOINT 255             // Setpoint for the middle sensor (ideally 255 or 0 - depending on what you want to sense)
#define MAX_MOTOR_SPEED 255     // Motor speed limits
#define MIN_MOTOR_SPEED 0

// Pins
#define LED_1 11    // LEDs are on pins 11,12,13
#define LED_2 12
#define LED_3 13

#define MOTOR_CONTROL 14
#define LEFT_MOTOR 15
#define RIGHT_MOTOR 16


// Define the sensor pins (ADC channels)
#define SENSOR_1 A1            // Pin 24
#define SENSOR_2 A2            // Pin 25
#define SENSOR_3 A3            // Pin 26 (Middle sensor)
#define SENSOR_4 A4            // Pin 27
#define SENSOR_5 A5            // Pin 28
#define SENSOR_COUNT 5         // Number of sensors

#endif