#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "motor.hpp"
#include "sensor.hpp"

//VL53L0X *mySensor = getSensor();
//VL53L0X *mySensor2 = getSensor();

void setup(){
  
  sensorSetup(); //Kør sensor setup en gang
  motorSetup();  
}

void loop(){
  sensor(); //loop sensor. sensor styre motor 

  Serial.println();
  delay(1);

}