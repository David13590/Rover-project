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
    enum runState{
        isStopped,
        isRunning,
    };
    runState myrunState = isStopped;
    switch(myrunState){
    case isStopped:
        if(gesture() == HIGH){
            myrunState = isRunning;
        }
        break;
    case isRunning:
        if(gesture() == HIGH){
            myrunState = isStopped;
        }
        break;
    }

    if(myrunState = isStopped){
        stopMotors();
        delay(1);
    }
    if(myrunState = isRunning){
        //decision();
        runMotors();
        Serial.println();
        delay(1);
    }
}


