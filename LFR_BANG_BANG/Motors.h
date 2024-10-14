#ifndef MOTORS_H
#define MOTORS_H

#include "config.h"

// Initialize motor outputs
void initMotors();      

// Set motor speeds
void setMotorSpeed(int16_t leftSpeed, int16_t rightSpeed); 

#endif