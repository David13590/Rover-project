#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"
#include "decision.hpp"
#include "buttonOnOff.hpp"


void setup(){
  motorSetup();
  sensorSetup();
  //motorCheck();
  
}

void loop(){
  while (buttonOnOff){
    //decision();
    runMotors();
    Serial.println();
    delay(1);
  }
    

}


