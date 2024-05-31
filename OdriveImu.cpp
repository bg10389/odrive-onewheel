#ifndef SENSORS_AND_CONTROL_H
#define SENSORS_AND_CONTROL_H

#include <MPU6050.h>
#include <Wire.h>

// Global variables
MPU6050 imu;
float pitchOffset = 0.0;

// IMU Functions
void setupIMU() {
    imu.initialize();
    if (!imu.testConnection()) {
        Serial.println("MPU6050 connection failed");
        while (1);
    }
}

void calibrateIMU() {
    // Calibrate the IMU
    // Implement your calibration logic here and set pitchOffset
}

float getIMUPitch() {
    int16_t ax, ay, az;
    imu.getAcceleration(&ax, &ay, &az);
    
    // Calculate pitch angle from accelerometer data
    float pitch = atan2(ax, sqrt(ay * ay + az * az)) * 180 / PI;
    
    return pitch - pitchOffset;
}

// ODrive Functions
void setupODrive() {
    // Add your ODrive setup code here
}

void controlODrive(float pitch) {
    // Placeholder values, adjust for your needs
    float throttle = map(pitch, -45, 45, -1, 1);
    
    // Send throttle to ODrive
    // Example: odrive.SetVelocity(0, throttle);
}

void stopODrive() {
    // Example: odrive.SetVelocity(0, 0);
}

// Footpad Functions
void setupFootpad() {
    // Initialize footpad pin
    pinMode(FOOTPAD_PIN, INPUT);
}

bool isFootpadPressed() {
    return digitalRead(FOOTPAD_PIN) == HIGH;
}

#endif
