#include "PID.h"


// Calculate the PID value
int16_t calculatePID(int16_t error, int16_t* prev_error, int16_t* integral) {
    // Calculate the integral, constrained to prevent windup
    *integral += error;
    *integral = constrain(*integral, -INTEGRAL_LIMIT, INTEGRAL_LIMIT);
    int16_t derivative = error - *prev_error;           // Calculate the derivative

    // Calculate the PID output
    int16_t pid_output = (Kp * error) + (Ki * (*integral)) + (Kd * derivative);

    *prev_error = error;                                // Store the current error as previous error for next calculation
    
    return pid_output;                                  // Return the calculated PID correction
}
