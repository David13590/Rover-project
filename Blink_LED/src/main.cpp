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
  int reactDistance[] = {70, 120, 200, 400, 500}; //Distance hvis sensor læser noget under, drej.

  if (mainSensorOutput->sensorDistanceLeft <= reactDistance[0]){
      //kør langsommere på højre / drej venstre
      SetLeftMotorsSpeed(1);
      SetRightMotorsSpeed(0);
  }
  else if (mainSensorOutput->sensorDistanceLeft <= reactDistance[1]){
      SetLeftMotorsSpeed(2);
      SetRightMotorsSpeed(1);
  }
  else if (mainSensorOutput->sensorDistanceLeft <= reactDistance[2]){
      SetLeftMotorsSpeed(3);
      SetRightMotorsSpeed(2);
  }
  else if (mainSensorOutput->sensorDistanceLeft <= reactDistance[3]){
      //Full speed ahead!!
      SetLeftMotorsSpeed(4);
      SetRightMotorsSpeed(4);
  }
  else if (mainSensorOutput->sensorDistanceLeft > reactDistance[4]){
      //Stop
      stopMotors();
  } 

  Serial.println();
  delay(1);

}