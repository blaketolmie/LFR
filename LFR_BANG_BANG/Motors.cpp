#include "Motors.h"

// Initialize motor outputs
void initMotors() {
    pinMode(LEFT_MOTOR, OUTPUT);
    pinMode(RIGHT_MOTOR, OUTPUT);
}

// Set motor speeds
void setMotorSpeed(int16_t leftSpeed, int16_t rightSpeed) {
    analogWrite(LEFT_MOTOR, leftSpeed);
    analogWrite(RIGHT_MOTOR, rightSpeed);
}