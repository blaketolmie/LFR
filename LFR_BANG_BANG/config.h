#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Motor speed limits
#define MAX_MOTOR_SPEED 255     
#define MIN_MOTOR_SPEED 0

// Pins
// https://camo.githubusercontent.com/b719fa994f4db0dd95e224fbdd939f93f7b6ba881b3c41e480b4733d4d82b6e6/68747470733a2f2f692e696d6775722e636f6d2f715849456368542e6a7067

#define LED_1 5    // LEDs are on pins 5,6,7 on Arduino 
#define LED_2 6
#define LED_3 7

#define MOTOR_CONTROL 8
#define LEFT_MOTOR 9
#define RIGHT_MOTOR 10

// Define the sensor pins (ADC channels)
#define SENSOR_1 A1            // Left sensor
#define SENSOR_2 A2
#define SENSOR_3 A3            // Middle sensor
#define SENSOR_4 A4
#define SENSOR_5 A5            // Right sensor

#endif
