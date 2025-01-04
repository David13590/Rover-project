#include <Arduino.h>
#include "roverControlMode.hpp"
#include "receiver.hpp"
#include "savedChannelData.hpp"
#include "decision.hpp"
#include "buttonModeSwitch.hpp"

static int gestureCount = 0;
int motorPercentForward[] = {0, 25, 50, 75, 100};
int motorPercentBackward[] = {-0, -25, -50, -75, -100};
int reactDistance[] = {100, 140, 180, 220, 280}; //Distance if sensor reads value under, turn.

decision::decisionReturnPercent myControlModeReturn;
int mode_select(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, bool gesture, int currentRoverMode){
    int buttonsPressedReturn = 0;
    buttonsPressedReturn = buttonSwitchDetect(joystick_data);
    if(gesture == HIGH || buttonsPressedReturn == true){
        gestureCount++;
        currentRoverMode = gestureCount;
    }
    if(gestureCount > roverControlModeEnumLength){
        gestureCount = 0;
        currentRoverMode = gestureCount;
    }
    return currentRoverMode;
}

decision::decisionReturnPercent mode_disarmed(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, bool gesture){
    int percentLeft = motorPercentForward[0];
    int percentRight = motorPercentForward[0];
    myControlModeReturn.motorPercentLeft = percentLeft;
    myControlModeReturn.motorPercentRight = percentRight;
    return myControlModeReturn; //Should return two structs??; motorPercent and armServo data 
}

decision::decisionReturnPercent mode_joystick_drive(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, bool gesture){
    if(joystick_data.joy1x > deadZoneMax){
        Serial.print("Forward");
        myControlModeReturn.motorPercentLeft = motorPercentForward[4];
        myControlModeReturn.motorPercentRight = motorPercentForward[4];
    }
    else if(joystick_data.joy1x < deadZoneMin){
        Serial.print("Backward");
        myControlModeReturn.motorPercentLeft = motorPercentBackward[4];
        myControlModeReturn.motorPercentRight = motorPercentBackward[4];
    }
    else{
        myControlModeReturn.motorPercentLeft = motorPercentForward[0];
        myControlModeReturn.motorPercentRight = motorPercentForward[0];
    }

    if(joystick_data.joy2y > deadZoneMax){
        myControlModeReturn.motorPercentLeft = motorPercentForward[4];
        myControlModeReturn.motorPercentRight = motorPercentForward[0];
    }
    else if(joystick_data.joy2y < deadZoneMin){
        myControlModeReturn.motorPercentLeft = motorPercentForward[0];
        myControlModeReturn.motorPercentRight = motorPercentForward[4];
    }
    else{
        myControlModeReturn.motorPercentLeft = motorPercentForward[0];
        myControlModeReturn.motorPercentRight = motorPercentForward[0]; 
    }
    return myControlModeReturn;
}

decision::decisionReturnPercent mode_joystick_grip(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, bool gesture){

    return myControlModeReturn;
}

decision::decisionReturnPercent mode_joystick_driveAvoid(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, bool gesture){

    return myControlModeReturn;
}

decision::decisionReturnPercent mode_sensorAvoid(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, bool gesture){
    //Højre motorsæt. Venstre sensor styre højre motorsæt
    myControlModeReturn.motorPercentRight = motorPercentForward[4];
    for(int i=4; i>=0; i--){
        if(sensor_distance.sensorDistanceLeft < reactDistance[i]){
            myControlModeReturn.motorPercentRight = motorPercentForward[i];
        }  
    } 

    //Venstre motor sæt. Højre sensor
    myControlModeReturn.motorPercentLeft = motorPercentForward[4];
    for(int i=4; i>=0; i--){
        if(sensor_distance.sensorDistanceRight < reactDistance[i]){
            myControlModeReturn.motorPercentLeft = motorPercentForward[i];
        }
    }
    return myControlModeReturn; 
}