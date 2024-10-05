#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"

VL53L0X Sensor;
VL53L0X Sensor2;

int XshutSensorPins[] = {ToFXshut1, ToFXshut2};

void sensorSetup(){
    pinMode(OUTPUT, XshutSensorPins[0]);
    pinMode(OUTPUT, XshutSensorPins[1]);

    Wire.begin();
    Serial.begin(115200);
    
    //digitalWrite(HIGH, XshutSensorPins[0]);
    //digitalWrite(LOW, XshutSensorPins[1]);
    
    
    //digitalWrite(HIGH, XshutSensorPins[0]); //Sluk sensor1, giv den en ny adresse
    // delay(150);
    // Sensor.init(true);
    // Sensor.setAddress((uint8_t)01);

    //Sluk sensor1, giv den en adresse 
    //digitalWrite(HIGH, XshutSensorPins[0]);
    //Sensor.init(true);
    //Sensor.setAddress((uint8_t)02);
    
     //sda 32, scl 33, 


    //Tænd sensor2, den får default adressen
    
    
    Sensor.startContinuous();
    //Sensor2.startContinuous();
}

void sensor(){
    int reactDistance[] = {70, 120, 200, 400, 500}; //Distance hvis sensor læser noget under, drej.
    int distanceLeft = Sensor.readRangeContinuousMillimeters();
    //int distanceRight = Sensor2.readRangeContinuousMillimeters();
    
    Serial.print("Distance: ");
    Serial.print(distanceLeft);
    Serial.print("mm ");

    // Serial.print("Distance: ");
    // Serial.print(distanceRight);
    // Serial.print("mm ");
    
    if (distanceLeft <= reactDistance[0]){
        //Meget tæt på væg, stop højre, langsomt venstre
        SetLeftMotorsSpeed(1);
        SetRightMotorsSpeed(0);
        analogWrite(LED, 255);
    }
    else if (distanceLeft <= reactDistance[1]){
        SetLeftMotorsSpeed(2);
        SetRightMotorsSpeed(1);
        analogWrite(LED, 60);
    }
    else if (distanceLeft <= reactDistance[2]){
        SetLeftMotorsSpeed(3);
        SetRightMotorsSpeed(2);
        analogWrite(LED, 10);
    }
    else if (distanceLeft <= reactDistance[3]){
        //Full speed ahead!!
        SetLeftMotorsSpeed(4);
        SetRightMotorsSpeed(4);
        analogWrite(LED, 0);
    }
    else if (distanceLeft > reactDistance[4]){
        //Stop
        stopMotors();
        analogWrite(LED, 0);
    }
}