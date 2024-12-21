#include <Arduino.h>
#include "motor.hpp"
#include "sensor.hpp"
#include "decision.hpp"
#include "receiver.hpp"

decision::decisionReturnPercent* decision::get_decision(){
    sensorClass::sensorReturnOutput* mainSensorOutput = mySensor.sensorRead(); //Get sensor readings
    saved_channel_data&  my_saved_channel_data = get_saved_channel_data(); //Get saved data from joystick
    
    //procent motor speed  0   25   50   75   100
    int reactDistance[] = {100, 140, 180, 220, 280}; //Distance hvis sensor læser noget under, drej.
    int motorPercent[] = {0, 25, 50, 75, 100};

    // //Højre motorsæt. Venstre sensor styre højre motorsæt
    // myMotorPercent.motorPercentRight = motorPercent[4];
    // for(int i=3; i>=0; i--){
    //     if(mainSensorOutput->sensorDistanceLeft < reactDistance[i]){
    //         myMotorPercent.motorPercentRight = motorPercent[i];
    //     }  
    // } 

    // //Venstre motor sæt. Højre sensor
    // myMotorPercent.motorPercentLeft = motorPercent[4];
    // for(int i=3; i>=0; i--){
    //     if(mainSensorOutput->sensorDistanceRight < reactDistance[i]){
    //         myMotorPercent.motorPercentLeft = motorPercent[i];
    //     }
    // }
    
    if(my_saved_channel_data.joy1x > deadZoneMax){
        Serial.print("RUN");
        myMotorPercent.motorPercentLeft = motorPercent[4];
        myMotorPercent.motorPercentRight = motorPercent[4];
    }
    else{
        myMotorPercent.motorPercentLeft = motorPercent[0];
        myMotorPercent.motorPercentRight = motorPercent[0];
    }

    //Debug stop
    // if (mainSensorOutput->sensorDistanceLeft > 1000){
    //     myMotorPercent.motorPercentRight = motorPercent[0];
    //      myMotorPercent.motorPercentLeft = motorPercent[0];
    // }
    Serial.print("*");
    return &myMotorPercent;
}