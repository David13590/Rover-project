#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "decision.hpp"



void decision(){

    int reactDistance = 50; //Distance hvis sensor læser noget under, drej.
    int distance = sensor.readRangeContinuousMillimeters();
    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("mm ");
    
    if (distance <= reactDistance){
    //kør langsommere på højre / drej venstre
    SetLeftMotorsSpeed(3);
    SetRightMotorsSpeed(1);

    analogWrite(LED, 255);
    }
    else if (distance > reactDistance){
        //Stop
        stopMotors();
        analogWrite(LED, 0);
    }
}


