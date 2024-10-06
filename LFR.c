#include <Arduino.h>

#define SENSOR_COUNT 5

// PID constants
#define Kp 2                  // Proportional
#define Ki 1                  // Integral
#define Kd 1                  // Derivative

// ADC channels for sensors (use analogRead on Arduino)
#define SENSOR_1 A0
#define SENSOR_2 A1
#define SENSOR_3 A2          // Middle sensor
#define SENSOR_4 A3
#define SENSOR_5 A4

#define SETPOINT 255          // Setpoint for the middle sensor (ideally 255)

void initMotors();                       // Initialize motor outputs
void setMotorSpeed(int8_t leftSpeed, int8_t rightSpeed); // Set motor speeds
int8_t calculatePID(int8_t error);      // Calculate PID correction
void initStatLEDs();                     // Initializes Stat LEDs
void turnOnLED1();                       // Turns on LED 1
void turnOnLED2();                       // Turns on LED 2
void turnOnLED3();                       // Turns on LED 3

void setup() {
    initStatLEDs();                       // Initialize LEDs
    initMotors();                         // Initialize motors
}

void loop() {
    int8_t sensorValues[SENSOR_COUNT];   // Array to hold sensor values
    sensorValues[0] = analogRead(SENSOR_1); // Read sensor 1
    sensorValues[1] = analogRead(SENSOR_2); // Read sensor 2
    sensorValues[2] = analogRead(SENSOR_3); // Read sensor 3 (middle)
    sensorValues[3] = analogRead(SENSOR_4); // Read sensor 4
    sensorValues[4] = analogRead(SENSOR_5); // Read sensor 5

    int8_t error = SETPOINT - sensorValues[2]; // Calculate error
    int8_t pid = calculatePID(error);            // Calculate PID value

    int8_t leftMotorSpeed = 127 + pid;  // Adjust left motor speed
    int8_t rightMotorSpeed = 127 - pid; // Adjust right motor speed

    setMotorSpeed(leftMotorSpeed, rightMotorSpeed); // Set motor speeds
    delay(100);                            // Delay for stability
}

void initMotors() {
    pinMode(5, OUTPUT); // Set pin 5 as output for left motor control
    pinMode(6, OUTPUT); // Set pin 6 as output for right motor control
}

void setMotorSpeed(int8_t leftSpeed, int8_t rightSpeed) {
    analogWrite(5, leftSpeed);   // Set left motor speed (connected to pin 5)
    analogWrite(6, rightSpeed);   // Set right motor speed (connected to pin 6)
}

int8_t calculatePID(int8_t error) {
    static int8_t prev_error = 0; // Previous error for derivative
    static int8_t integral = 0;    // Integral accumulator
    integral += error;             // Calculate integral
    int8_t derivative = error - prev_error; // Calculate derivative
    int8_t pid_output = (Kp * error) + (Ki * integral) + (Kd * derivative); // PID output
    prev_error = error;            // Store current error as previous error
    return pid_output;             // Return PID correction value
}

void initStatLEDs() {
    pinMode(7, OUTPUT); // Set pin 7 as output for LED1
    pinMode(8, OUTPUT); // Set pin 8 as output for LED2
    pinMode(9, OUTPUT); // Set pin 9 as output for LED3
}

void turnOnLED1() {
    digitalWrite(7, HIGH); // Turns on LED 1
}

void turnOnLED2() {
    digitalWrite(8, HIGH); // Turns on LED 2
}

void turnOnLED3() {
    digitalWrite(9, HIGH); // Turns on LED 3
}
