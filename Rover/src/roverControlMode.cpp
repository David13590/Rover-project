#include <Arduino.h>
#include "roverControlMode.hpp"
#include "receiver.hpp"
#include "savedChannelData.hpp"
#include "decision.hpp"
#include "buttonModeSwitch.hpp"
#include "arm.hpp"

static int gestureCount = 0;
int motorPercentForward[] = {0, 25, 50, 75, 100};
int motorPercentBackward[] = {-0, -25, -50, -75, -100};
int reactDistance[] = {220, 250, 270, 350, 400}; //Distance if sensor reads value under, turn.

decision::decisionReturnPercent myControlModeReturn;
int mode_select(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, int currentRoverMode){
    int buttonsPressedReturn = 0;
    buttonsPressedReturn = buttonSwitchDetect(joystick_data);
    if(/* gesture == HIGH || */ buttonsPressedReturn == true){
        gestureCount++;
        currentRoverMode = gestureCount;
    }
    if(gestureCount > roverControlModeEnumLength){
        gestureCount = 0;
        currentRoverMode = gestureCount;
    }
    return currentRoverMode;
}

decision::decisionReturnPercent mode_disarmed(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance){
    myControlModeReturn.motorPercentLeft = motorPercentForward[0];
    myControlModeReturn.motorPercentRight = motorPercentForward[0];
    myControlModeReturn.motorPercentLeft = motorPercentBackward[0];
    myControlModeReturn.motorPercentRight = motorPercentBackward[0];
    return myControlModeReturn; //Should return two structs??; motorPercent and armServo data 
}

decision::decisionReturnPercent mode_joystick_drive(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance){
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
        myControlModeReturn.motorPercentLeft = motorPercentBackward[0];
        myControlModeReturn.motorPercentRight = motorPercentBackward[0];
    }

    if(joystick_data.joy2y > deadZoneMax){
        myControlModeReturn.motorPercentLeft = motorPercentForward[0];
        myControlModeReturn.motorPercentRight = motorPercentForward[4];
    }
    else if(joystick_data.joy2y < deadZoneMin){
        myControlModeReturn.motorPercentLeft = motorPercentForward[4];
        myControlModeReturn.motorPercentRight = motorPercentForward[0];
    }
    return myControlModeReturn;
}

decision::decisionReturnPercent mode_joystick_grip(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance, armClass& arm){
    //Serial.print("IN ARM MODE ");
    myControlModeReturn.servoYawTarget = arm.yawCurrentPos;
    myControlModeReturn.servoPitchTarget = arm.pitchCurrentPos;
    myControlModeReturn.servoForwardBackTarget = arm.forwardBackCurrentPos;
    myControlModeReturn.servoGripTarget = arm.gripCurrentPos;

    if(joystick_data.joy2y > deadZoneMax){ //Yaw right
        Serial.print("Moving yaw");
        myControlModeReturn.servoYawTarget = arm.yawCurrentPos + arm.decrement;
        arm.yawCurrentPos = myControlModeReturn.servoYawTarget;
    }
    if(arm.yawCurrentPos < arm.yawMin){arm.yawCurrentPos = arm.yawMin;}
    if(joystick_data.joy2y < deadZoneMin){ //Yaw left
        Serial.print("Moving yaw");
        myControlModeReturn.servoYawTarget = arm.yawCurrentPos + arm.increment;
        arm.yawCurrentPos = myControlModeReturn.servoYawTarget;
    }
    if(arm.yawCurrentPos > arm.yawMax){arm.yawCurrentPos = arm.yawMax;}


    if(joystick_data.joy1y > deadZoneMax){ //Pitch down
        Serial.print("Moving pitch");
        myControlModeReturn.servoPitchTarget = arm.pitchCurrentPos + arm.decrement;
        arm.pitchCurrentPos = myControlModeReturn.servoPitchTarget;
    }
    if(arm.pitchCurrentPos > arm.pitchMax){arm.pitchCurrentPos = arm.pitchMax;}
    if(joystick_data.joy1y < deadZoneMin){ //Pitch up
        Serial.print("Moving pitch");
        myControlModeReturn.servoPitchTarget = arm.pitchCurrentPos + arm.increment;
        arm.pitchCurrentPos = myControlModeReturn.servoPitchTarget;
    }
    if(arm.pitchCurrentPos < arm.pitchMin){arm.pitchCurrentPos = arm.pitchMin;}


    if(joystick_data.joy1x > deadZoneMax){ //ForwardBack
        Serial.print("Moving ForwardBack");
        myControlModeReturn.servoForwardBackTarget = arm.forwardBackCurrentPos + arm.increment;
        arm.forwardBackCurrentPos = myControlModeReturn.servoForwardBackTarget;
    }
    if(arm.forwardBackCurrentPos > arm.forwardBackMax){arm.forwardBackCurrentPos = arm.forwardBackMax;}
    if(joystick_data.joy1x < deadZoneMin){ //ForwardBack
        Serial.print("Moving ForwardBack");
        myControlModeReturn.servoForwardBackTarget = arm.forwardBackCurrentPos + arm.decrement;
        arm.forwardBackCurrentPos = myControlModeReturn.servoForwardBackTarget;
    }
    if(arm.forwardBackCurrentPos < arm.forwardBackMin){arm.forwardBackCurrentPos = arm.forwardBackMin;}


    if(joystick_data.joy2x > deadZoneMax){ //Grip 
        Serial.print("Moving Grip");
        myControlModeReturn.servoGripTarget = arm.gripCurrentPos + arm.increment;
        arm.gripCurrentPos = myControlModeReturn.servoGripTarget;
    }
    if(arm.gripCurrentPos > arm.gripMax){arm.gripCurrentPos = arm.gripMax;}
    if(joystick_data.joy2x < deadZoneMin){ //Grip
        Serial.print("Moving Grip");
        myControlModeReturn.servoGripTarget = arm.gripCurrentPos + arm.decrement;
        arm.gripCurrentPos = myControlModeReturn.servoGripTarget;
    }
    if(arm.gripCurrentPos < arm.gripMin){arm.gripCurrentPos = arm.gripMin;}
    return myControlModeReturn;
}

decision::decisionReturnPercent mode_joystick_driveAvoid(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance){

    return myControlModeReturn;
}

decision::decisionReturnPercent mode_sensorAvoid(saved_channel_data joystick_data, sensorClass::sensorReturnOutput sensor_distance){
        //Højre motorsæt. Venstre sensor styre højre motorsæt
        myControlModeReturn.motorPercentRight = motorPercentForward[4];
        for(int i=3; i>=0; i--){
            if(sensor_distance.sensorDistanceLeft < reactDistance[i]){
                myControlModeReturn.motorPercentRight = motorPercentForward[i];
            }  
        } 

        //Venstre motor sæt. Højre sensor
        myControlModeReturn.motorPercentLeft = motorPercentForward[4];
        for(int i=3; i>=0; i--){
            if(sensor_distance.sensorDistanceRight < reactDistance[i]){
                myControlModeReturn.motorPercentLeft = motorPercentForward[i];
            }
        }
    return myControlModeReturn;
}