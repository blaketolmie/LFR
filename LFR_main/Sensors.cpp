#include "Sensors.h"


// Initialize the sensor pins
void initSensors() {
    pinMode(SENSOR_1, INPUT);
    pinMode(SENSOR_2, INPUT);
    pinMode(SENSOR_3, INPUT);
    pinMode(SENSOR_4, INPUT);
    pinMode(SENSOR_5, INPUT);

    Serial.println("All sensors set to input");
}

// Read sensor values into an array
void readSensors(int16_t* sensorValues) {
    // Read sensor values from the defined analog pins
    sensorValues[0] = analogRead(SENSOR_1);
    sensorValues[1] = analogRead(SENSOR_2);
    sensorValues[2] = analogRead(SENSOR_3);
    sensorValues[3] = analogRead(SENSOR_4);
    sensorValues[4] = analogRead(SENSOR_5);

    Serial.println("Sensor 1 is value: " + String(sensorValues[0]));
    Serial.println("Sensor 2 is value: " + String(sensorValues[1]));
    Serial.println("Sensor 3 is value: " + String(sensorValues[2]));
    Serial.println("Sensor 4 is value: " + String(sensorValues[3]));
    Serial.println("Sensor 5 is value: " + String(sensorValues[4]));
}
