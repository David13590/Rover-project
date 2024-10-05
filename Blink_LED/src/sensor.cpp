#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"


VL53L0X sensor;
VL53L0X sensor2;

void sensorSetup(){
    pinMode(XshutSensor1, OUTPUT);
    pinMode(XshutSensor2, OUTPUT);

    //Tænd alle sensors
    digitalWrite(XshutSensor1, LOW);//active low, slukker sensor når HIGH
    digitalWrite(XshutSensor2, LOW);

    Serial.begin(115200);
    Wire.begin();
    
    //Sluk sensor1
    digitalWrite(XshutSensor1, HIGH); //Sluk en efter en og sæt adresse
    delay(150);
    sensor.init(true);
    sensor.setAddress((uint8_t)01); //Ny adresse

    //Sluk sensor2
    digitalWrite(XshutSensor2, HIGH);
    delay(150);
    sensor2.init(true);
    sensor2.setAddress((uint8_t)02); 
    
    sensor.startContinuous();
    sensor2.startContinuous();
    
}

void sensorRead(){
    int reactDistance = 50; //Distance hvis sensor læser noget under, drej.
    int distanceLeft = sensor.readRangeContinuousMillimeters();
    int distanceRight = sensor2.readRangeContinuousMillimeters();

    Serial.print("DistanceLeft: ");
    Serial.print(distanceLeft);
    Serial.print("mm ");
    
    Serial.print("DistanceRight: ");
    Serial.print(distanceRight);
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

