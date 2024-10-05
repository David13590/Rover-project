#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"


void setup(){
  motorSetup();
  sensorSetup();
  
}

void loop(){
  sensorReturnOutput* mainSensorOutput = sensorRead();
  int reactDistance = 50; //Distance hvis sensor læser noget under, drej.

  if (mainSensorOutput->sensorDistanceLeft <= reactDistance){
    //kør langsommere på højre / drej venstre
    SetLeftMotorsSpeed(3);
    SetRightMotorsSpeed(1);

    //analogWrite(LED, 255);
  }
  else if (mainSensorOutput->sensorDistanceLeft > reactDistance){
      //Stop
      stopMotors();
      //analogWrite(LED, 0);
  } 

  Serial.println();
  delay(1);

}