#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"

VL53L0X sensor;

#define LED 17

//Pins der skal sættes som output
int pins[] = {LED, motorFL1, motorFL2, motorFR1, motorFR2, motorBL1, motorBL2, motorBR1, motorBR2}; 

int reactDistance = 50; //Distance hvis sensor læser noget under, drej.

void setup(){
  Serial.begin(115200);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  //Finder længden af pins array, sætter pins i array som digital eller analog output
  int pinArrayLen = sizeof(pins)/sizeof(pins[0]);
  for(int i; i < pinArrayLen; i++){
    pinMode(pins[i], OUTPUT);
    analogWrite(pins[i], 0);
  }

}

void loop(){
  int distance = sensor.readRangeContinuousMillimeters();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm ");
  
  
  if (distance <= reactDistance){
    //kør langsommere på højre / drej venstre
    //SetLeftMotorsSpeed(3);
    SetRightMotorsSpeed(3);

    analogWrite(LED, 255);
  }
  else if (distance > reactDistance){
    //Stop
    
    stopMotors();
    analogWrite(LED, 0);
  }

  Serial.println();
  delay(1);

}