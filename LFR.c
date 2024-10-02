// define pins used on microcontroller

// reading the sensors (based on hardware - ADC convert 8-bit number from 0 to 255)
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>     // not used in this code yet

#define F_CPU 9216000UL			// Updated clock frequency (9.216 MHz)
#define SENSOR_COUNT 5

// PID constants
#define Kp 2						// Proportional
#define Ki 1						// Integral
#define Kd 1						// Derivative

// ADC channels for sensors
#define SENSOR_1 0
#define SENSOR_2 1
#define SENSOR_3 2				// Middle sensor
#define SENSOR_4 3
#define SENSOR_5 4

#define SETPOINT 255				// Setpoint for the middle sensor (ideally 255)

// Function prototypes
void initADC(void);					// Initialize ADC
int8_t readADC(uint8_t channel);	// Read value from ADC channel
void initMotors(void);				// Initialize motor outputs
void setMotorSpeed(int8_t leftSpeed, int8_t rightSpeed); // Set motor speeds
int8_t calculatePID(int8_t error);  // Calculate PID correction
void init_stat_LEDS (void);         // Initializes Stat LEDs
void turn_on_LED1 (void);           // Turns on LED 1
void turn_on_LED2 (void);           // Turns on LED 2
void turn_on_LED3 (void);           // Turns on LED 3

int main() 
{
    init_stat_LEDS();           // Initialize LEDs
	initADC();					// Initialize ADC
	initMotors();				// Initialize motors

	int8_t prev_error = 0;		// Previous error for PID
	int8_t integral = 0;		// Integral part of PID

	while (1) {
		int8_t sensorValues[SENSOR_COUNT]; // Array to hold sensor values
		sensorValues[0] = readADC(SENSOR_1); // Read sensor 1
		sensorValues[1] = readADC(SENSOR_2); // Read sensor 2
		sensorValues[2] = readADC(SENSOR_3); // Read sensor 3 (middle)
		sensorValues[3] = readADC(SENSOR_4); // Read sensor 4
		sensorValues[4] = readADC(SENSOR_5); // Read sensor 5

		int8_t error = SETPOINT - sensorValues[2];  // Calculate error
		int8_t pid = calculatePID(error);           // Calculate PID value

		int8_t leftMotorSpeed = 127 + pid;  // Adjust left motor speed
		int8_t rightMotorSpeed = 127 - pid; // Adjust right motor speed

		setMotorSpeed(leftMotorSpeed, rightMotorSpeed); // Set motor speeds
		_delay_ms(100);			            // Delay for stability
	}

	return 0;
}

void initMotors(void) 
{
	DDRD |= (1 << PIN_PB5) | (1 << PIN_PB6); // Set PD5 and PD6 as output for motor control
}

void setMotorSpeed(int8_t leftSpeed, int8_t rightSpeed) 
{
	PIN_PB2 = leftSpeed;				    // Set left motor speed (connected to PB2)
	PIN_PB1 = rightSpeed;				    // Set right motor speed (connected to PB1)
}

int8_t calculatePID(int8_t error) 
{
	static int8_t prev_error = 0;	        // Previous error for derivative
	static int8_t integral = 0;		        // Integral accumulator
	integral += error;				        // Calculate integral
	int8_t derivative = error - prev_error; // Calculate derivative
	int8_t pid_output = (Kp * error) + (Ki * integral) + (Kd * derivative); // PID output
	prev_error = error;				        // Store current error as previous error
	return pid_output;				        // Return PID correction value
}

void init_stat_LEDS (void) 
{
    DDRD |= (1 << PIN_PD5) | (1 << PIN_PD6) | (1 << PIN_PD7); // Set PD5, PD6 and PD7 as output
}

void turn_on_LED1 (void)           // Turns on LED 1
{
    

}
void turn_on_LED2 (void)           // Turns on LED 2
{

}

void turn_on_LED3 (void)           // Turns on LED 3
{

}



/* WORK AND PROGRESS DOWN BELOW */
void initADC(void) 
{
	ADMUX = (1 << REFS0);			// Set reference voltage to AVcc
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Enable ADC with prescaler of 64
}

int8_t readADC(uint8_t channel) 
{
	ADMUX = (ADMUX & 0xF8) | (channel & 0x07); // Select the correct ADC channel
	ADCSRA |= (1 << ADSC);			// Start ADC conversion
	while (ADCSRA & (1 << ADSC));	// Wait for conversion to complete
	return (int8_t)(ADC >> 2);		// Return 8-bit result
}