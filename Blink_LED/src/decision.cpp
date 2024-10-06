#include <Arduino.h>
#include "motor.hpp"
#include "sensor.hpp"
#include "decision.hpp"


static decisionReturnPercent myMotorPercent;
decisionReturnPercent* decision(){
    sensorReturnOutput* mainSensorOutput = sensorRead();
    //procent motor speed  0   25   50   75   100
    int reactDistance[] = {70, 120, 200, 400, 500}; //Distance hvis sensor læser noget under, drej.
    int motorPercent[] = {0, 25, 50, 75, 100};

    //Højre motorsæt. Venstre sensor styre højre motorsæt
    myMotorPercent.motorPercentRight = motorPercent[4];
    for(int i=3; i>=0; i--){
        if(mainSensorOutput->sensorDistanceLeft < reactDistance[i]){
            myMotorPercent.motorPercentRight = motorPercent[i];
        }
        
    } 
    //Venstre motor sæt. Højre sensor
    if (mainSensorOutput->sensorDistanceRight < reactDistance[0]){
        myMotorPercent.motorPercentLeft = motorPercent[0];
    }
    else if (mainSensorOutput->sensorDistanceRight < reactDistance[1]){
        myMotorPercent.motorPercentLeft = motorPercent[1];
    }
    else if (mainSensorOutput->sensorDistanceRight < reactDistance[2]){
        myMotorPercent.motorPercentLeft = motorPercent[2];
    }
    else if (mainSensorOutput->sensorDistanceRight < reactDistance[3]){
        myMotorPercent.motorPercentLeft = motorPercent[3];
    }
    else {
        myMotorPercent.motorPercentLeft = motorPercent[4];
    }


    //Debug stop
    if (mainSensorOutput->sensorDistanceLeft > 1000){
        myMotorPercent.motorPercentRight = motorPercent[0];
        myMotorPercent.motorPercentLeft = motorPercent[0];
    }

    return &myMotorPercent;

}