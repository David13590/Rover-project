#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"
#include "decision.hpp"
#include "gesture.hpp"
motor mainMotor;
gesture mainGesture;
sensorClass mainSensor;

void setup(){
  mainSensor.sensorSetup();
  mainGesture.gestureSetup();
  mainMotor.motorSetup();
  //motorCheck();
  
}

void loop(){
  static int state = 0;
  if(state == 0){
      if(mainGesture.readGesture() == HIGH){
          state = 1;
      }
  }
  if(state == 1){
      if(mainGesture.readGesture() == HIGH){
          state = 0;
      }
  }
  
  Serial.print(state);
  if(state == 0){
    mainMotor.stopMotors();
    delay(1);
  }
  if(state == 1){
    //decision();
    mainMotor.runMotors();
    Serial.println();
    delay(1);
  }

}


