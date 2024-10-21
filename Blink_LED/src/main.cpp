#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"
#include "decision.hpp"
#include "gesture.hpp"


void setup(){
  sensorSetup();
  gestureSetup();
  motorSetup();
  //motorCheck();
  
}

void loop(){
  static int state = 0;
  if(state == 0){
      if(gesture() == HIGH){
          state = 1;
      }
  }
  if(state == 1){
      if(gesture() == HIGH){
          state = 0;
      }
  }
  
  Serial.print(state);
  if(state == 0){
    stopMotors();
    delay(1);
  }
  if(state == 1){
    //decision();
    runMotors();
    Serial.println();
    delay(1);
  }

}


