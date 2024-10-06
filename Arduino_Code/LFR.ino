#include <Arduino.h>
// https://docs.arduino.cc/programming/
#define SENSOR_COUNT 5

// PID constants
#define Kp 2.0                 // Proportional
#define Ki 1.0                 // Integral
#define Kd 1.0                 // Derivative

// ADC channels for sensors (use analogRead on Arduino)
#define SENSOR_1 A0            // Pin 23
#define SENSOR_2 A1            // Pin 24
#define SENSOR_3 A2            // Pin 25 (Middle sensor)
#define SENSOR_4 A3            // Pin 26
#define SENSOR_5 A4            // Pin 27

#define SETPOINT 255           // Setpoint for the middle sensor (ideally 255)

// Motor speed limits
#define MAX_MOTOR_SPEED 255
#define MIN_MOTOR_SPEED 0
#define INTEGRAL_LIMIT 100     // Limit for the integral term to prevent windup

void initMotors();                             // Initialize motor outputs
void setMotorSpeed(int16_t leftSpeed, int16_t rightSpeed); // Set motor speeds
int16_t calculatePID(int16_t error);          // Calculate PID correction
void initStatLEDs();                           // Initializes Status LEDs
void turnOnLED(int ledNumber);                 // Turns on specified LED
void turnOffLED(int ledNumber);                // Turns off specified LED

void setup() {
    initStatLEDs();                             // Initialize LEDs
    initMotors();                               // Initialize motors
}

void loop() {
    int16_t sensorValues[SENSOR_COUNT];        // Array to hold sensor values

    // Read sensor values
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensorValues[i] = analogRead(A0 + i);  // Read sensors from A0 to A4
    }

    int16_t error = SETPOINT - sensorValues[2]; // Calculate error
    int16_t pid = calculatePID(error);           // Calculate PID value

    int16_t leftMotorSpeed = 127 + pid;         // Adjust left motor speed
    int16_t rightMotorSpeed = 127 - pid;        // Adjust right motor speed

    // Clamp motor speed values to defined limits
    leftMotorSpeed = constrain(leftMotorSpeed, MIN_MOTOR_SPEED, MAX_MOTOR_SPEED);
    rightMotorSpeed = constrain(rightMotorSpeed, MIN_MOTOR_SPEED, MAX_MOTOR_SPEED);

    setMotorSpeed(leftMotorSpeed, rightMotorSpeed); // Set motor speeds
    delay(100);                                    // Delay for stability
}

void initMotors() {
    pinMode(15, OUTPUT); // Set pin 15 as output for left motor control (Motor 1)
    pinMode(16, OUTPUT); // Set pin 16 as output for right motor control (Motor 2)
}

void setMotorSpeed(int16_t leftSpeed, int16_t rightSpeed) {
    analogWrite(15, leftSpeed);   // Set left motor speed (connected to pin 15)
    analogWrite(16, rightSpeed);   // Set right motor speed (connected to pin 16)
}

int16_t calculatePID(int16_t error) {
    static int16_t prev_error = 0; // Previous error for derivative
    static int16_t integral = 0;    // Integral accumulator

    // Calculate integral with clamping
    integral += error;
    integral = constrain(integral, -INTEGRAL_LIMIT, INTEGRAL_LIMIT);

    // Calculate derivative
    int16_t derivative = error - prev_error;

    // Calculate PID output
    int16_t pid_output = (Kp * error) + (Ki * integral) + (Kd * derivative);

    // Store current error as previous error
    prev_error = error;

    return pid_output; // Return PID correction value
}

void initStatLEDs() {
    pinMode(11, OUTPUT); // Set pin 11 as output for LED1 (STAT1)
    pinMode(12, OUTPUT); // Set pin 12 as output for LED2 (STAT2)
    pinMode(13, OUTPUT); // Set pin 13 as output for LED3 (STAT3)
}

void turnOnLED(int ledNumber) {
    digitalWrite(ledNumber, HIGH); // Turns on specified LED
}

void turnOffLED(int ledNumber) {
    digitalWrite(ledNumber, LOW); // Turns off specified LED
}
