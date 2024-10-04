#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "decision.hpp"

VL53L0X sensor;

//Pins der skal sættes som output
int pins[] = {LED, motorFL1, motorFL2, motorFR1, motorFR2, motorBL1, motorBL2, motorBR1, motorBR2};

void setup(){
  Serial.begin(115200);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  //Finder længden af pins array, sætter pins i array som analog output
  int pinArrayLen = sizeof(pins)/sizeof(pins[0]);
  for(int i; i < pinArrayLen; i++){
    pinMode(pins[i], OUTPUT);
    analogWrite(pins[i], 0);
  }

}

void loop(){
  

  Serial.println();
  delay(1);

}