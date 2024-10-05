#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"

VL53L0X sensor;
VL53L0X sensor2;

void sensorSetup(){
    
    
    
    Wire.begin();
    
    
    sensor.init();
    sensor.setTimeout(500);
    
    
    
    
    sensor.startContinuous();
    
}

void sensorRead(){
    int reactDistance = 50; //Distance hvis sensor læser noget under, drej.
    int distanceLeft = sensor.readRangeContinuousMillimeters();
    
    Serial.print("Distance: ");
    Serial.print(distanceLeft);
    Serial.print("mm ");
    
    if (distanceLeft <= reactDistance){
    //kør langsommere på højre / drej venstre
    SetLeftMotorsSpeed(3);
    SetRightMotorsSpeed(1);

    analogWrite(LED, 255);
    }
    else if (distanceLeft > reactDistance){
        //Stop
        stopMotors();
        analogWrite(LED, 0);
    }
}

