#ifndef PID_H
#define PID_H

#include "config.h"

// Calculate the PID value
int16_t calculatePID(int16_t error, int16_t* prev_error, int16_t* integral);

#endif
