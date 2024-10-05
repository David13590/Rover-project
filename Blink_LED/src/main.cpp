#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"


//Pins der skal sættes som output
int pins[] = {LED, motorFL1, motorFL2, motorFR1, motorFR2, motorBL1, motorBL2, motorBR1, motorBR2};

void setup(){
  
  sensorSetup();

  //Finder længden af pins array, sætter pins i array som analog output
  int pinArrayLen = sizeof(pins)/sizeof(pins[0]);
  for(int i; i < pinArrayLen; i++){
    pinMode(pins[i], OUTPUT);
    analogWrite(pins[i], 0);
  }

}

void loop(){
  sensorRead();

  Serial.println();
  delay(1);

}