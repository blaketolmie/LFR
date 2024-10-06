#ifndef SENSORS_H
#define SENSORS_H

#include "config.h"

// Initialize sensor pins
void initSensors();

// Read all sensor values into an array
void readSensors(int16_t* sensorValues);

#endif