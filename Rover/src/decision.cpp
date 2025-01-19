#include <Arduino.h>
#include "decision.hpp"
#include "savedChannelData.hpp"
#include "roverControlMode.hpp"
#include "arm.hpp"

decision::decision(armClass& Arm): myArm{Arm}{}
decision::decisionReturnPercent* decision::get_decision(){
    sensorClass::sensorReturnOutput& mainSensorOutput = mySensor.sensorRead(); //Get sensor readings
    saved_channel_data&  my_saved_channel_data = get_saved_channel_data(); //Get saved data from joystick
    //bool readDecisionGesture = decisionGesture.readGesture();

    currentRoverMode = mode_select(my_saved_channel_data, mainSensorOutput, currentRoverMode);
    Serial.print(currentRoverMode);
    static int lastModeChangeTime = 0;
    static int lastMode = 0;
    if(lastMode !=currentRoverMode){ //Start taking time when mode has changed
        lastModeChangeTime = millis();
        lastMode = currentRoverMode;
    }
    switch (currentRoverMode){
    default://disarmed
        myMotorPercent = mode_disarmed(my_saved_channel_data, mainSensorOutput);
        Serial.print("Mode: disarmed  ");
        break;
    case joystickDrive:
        myMotorPercent = mode_joystick_drive(my_saved_channel_data, mainSensorOutput);
        Serial.print("Mode: joystickDrive  ");
        break;
    case joystickGrip:
        myMotorPercent = mode_joystick_grip(my_saved_channel_data, mainSensorOutput, myArm);
        Serial.print("Mode: joystickGrip  ");
        break;
    // case joystickDriveAvoid:
    //     myMotorPercent = mode_joystick_driveAvoid(my_saved_channel_data, mainSensorOutput, readDecisionGesture);
    //     Serial.print("Mode: joystickDriveAvoid");
    //     break;
    case sensorAvoidWait:
        if(millis() - lastModeChangeTime > sensorAvoidStartDelay){
            currentRoverMode = sensorAvoid;
        }
        Serial.print("Mode: sensorWait ");
        Serial.print(millis() - lastModeChangeTime);
        break;
    case sensorAvoid:
        myMotorPercent = mode_sensorAvoid(my_saved_channel_data, mainSensorOutput);
        Serial.print("Mode: sensorAvoid  ");
        break;
    }
    return &myMotorPercent;
}