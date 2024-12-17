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
  static int gestureState = 0;
  if(gestureState == 0){
      if(mainGesture.readGesture() == HIGH){
          gestureState = 1;
      }
  }
  if(gestureState == 1){
      if(mainGesture.readGesture() == HIGH){
          gestureState = 0;
      }
  }
  
  //Serial.print(state);
  if(gestureState == 0){
    mainMotor.stopMotors();
    delay(1);
  }
  if(gestureState == 1){
    //decision();
    mainMotor.runMotors();
    Serial.println();
    delay(1);
  }
}


