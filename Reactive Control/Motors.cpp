#include "Motors.h"

// Initialize motor outputs
void initMotors() {
    pinMode(LEFT_MOTOR, OUTPUT);
    pinMode(RIGHT_MOTOR, OUTPUT);
}

// Set motor speeds
void setMotorSpeed(int16_t leftSpeed, int16_t rightSpeed) {
    // Constraining the motor speeds so the circuit wont get damaged by accidentally setting motor values above too high
    analogWrite(LEFT_MOTOR, constrain(leftSpeed, MIN_MOTOR_SPEED, MAX_MOTOR_SPEED));
    analogWrite(RIGHT_MOTOR, constrain(rightSpeed, MIN_MOTOR_SPEED, MAX_MOTOR_SPEED));
}