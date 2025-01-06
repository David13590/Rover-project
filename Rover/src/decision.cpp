#include <Arduino.h>
#include "decision.hpp"
#include "savedChannelData.hpp"
#include "roverControlMode.hpp"

decision::decisionReturnPercent* decision::get_decision(){
    sensorClass::sensorReturnOutput& mainSensorOutput = mySensor.sensorRead(); //Get sensor readings
    saved_channel_data&  my_saved_channel_data = get_saved_channel_data(); //Get saved data from joystick
    //bool readDecisionGesture = decisionGesture.readGesture();

    currentRoverMode = mode_select(my_saved_channel_data, mainSensorOutput, currentRoverMode);
    Serial.print(currentRoverMode);
    switch (currentRoverMode){
    default://disarmed
        myMotorPercent = mode_disarmed(my_saved_channel_data, mainSensorOutput);
        Serial.print("Mode: disarmed");
        break;
    case joystickDrive:
        myMotorPercent = mode_joystick_drive(my_saved_channel_data, mainSensorOutput);
        Serial.print("Mode: joystickDrive");
        break;
    case joystickGrip:
        myMotorPercent = mode_joystick_grip(my_saved_channel_data, mainSensorOutput);
        Serial.print("Mode: joystickGrip");
        break;
    // case joystickDriveAvoid:
    //     myMotorPercent = mode_joystick_driveAvoid(my_saved_channel_data, mainSensorOutput, readDecisionGesture);
    //     Serial.print("Mode: joystickDriveAvoid");
    //     break;
    case sensorAvoid:
        myMotorPercent = mode_sensorAvoid(my_saved_channel_data, mainSensorOutput);
        Serial.print("Mode: sensorAvoid");
        break;
    }
    return &myMotorPercent;
}