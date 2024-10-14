#include "Motors.h"

// Initialize motor outputs
void initMotors() {
    pinMode(LEFT_MOTOR, OUTPUT);
    pinMode(RIGHT_MOTOR, OUTPUT);

    Serial.println("LEFT_MOTOR set to output");
    Serial.println("RIGHT_MOTOR set to output");
}

// Set motor speeds
void setMotorSpeed(int16_t leftSpeed, int16_t rightSpeed) {
    analogWrite(LEFT_MOTOR, leftSpeed);
    analogWrite(RIGHT_MOTOR, rightSpeed);

    Serial.println("Sensor 1 LEFT_MOTOR is value: " + String(leftSpeed));
    Serial.println("Sensor 1 RIGHT_MOTOR is value: " + String(rightSpeed));
}