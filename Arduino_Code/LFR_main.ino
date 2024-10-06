#include <Arduino.h>
#include "Motors.h"
#include "LEDs.h"
#include "PID.h"
#include "Sensors.h"
#include "config.h"

// Variables to store the previous error and integral value
int16_t prev_error = 0;
int16_t integral = 0;

unsigned long startTime;                        // Variable to store the time when the loop starts
unsigned long endTime = 60;                     // Run program for 60 seconds - remove at end after testing

void setup() {
    Serial.begin(9600);                         // Initialize serial communication
    initStatLEDs();                             // Initialize LEDs
    initMotors();                               // Initialize motors
    initSensors();                              // Initialize sensors
    pinMode(MOTOR_CONTROL, INPUT);              // Set the MOTOR_CONTROL pin as an input
    Serial.println("Set up complete");
    startTime = millis();                       // Store the start time when the program begins
}

void loop() {
    int turn_off = digitalread(MOTOR_CONTROL);  // check if digital high or low
    int16_t sensorValues[SENSOR_COUNT];         // Array to hold sensor values
    readSensors(sensorValues);                  // Read sensor values using the new sensor module
    int16_t error = SETPOINT - sensorValues[2]; // Calculate error (middle sensor)
    
    // Calculate PID value using the new module and pass prev_error and integral by pointer
    int16_t pid = calculatePID(error, &prev_error, &integral);
    Serial.println("PID: " + String(pid));
    int16_t leftMotorSpeed = 127 + pid;         // Adjust left motor speed
    int16_t rightMotorSpeed = 127 - pid;        // Adjust right motor speed

    // Clamp motor speed values to defined limits
    leftMotorSpeed = constrain(leftMotorSpeed, MIN_MOTOR_SPEED, MAX_MOTOR_SPEED);
    rightMotorSpeed = constrain(rightMotorSpeed, MIN_MOTOR_SPEED, MAX_MOTOR_SPEED);

    setMotorSpeed(leftMotorSpeed, rightMotorSpeed); // Set motor speeds

    // End program if button is pressed - can change it to turning off the motors etc
    if (turn_off == HIGH) {     
        Serial.println("PROGRAM END");
        break;
    }
    
    // Exit the loop after endTime seconds
    if ((millis() - startTime) >= (endTime*1000)) {
        Serial.println(String(endTime) + " seconds have passed. PROGRAM END.");
        return;  
    }

    delay(500);     // Delay for 0.5 seconds (for stability) - reduce to 0.1 seconds after removing serial communication println's
}
