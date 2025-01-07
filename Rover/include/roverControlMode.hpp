#ifndef ROVERCONTROLMODE_HPP_
#define ROVERCONTROLMODE_HPP_
#include "savedChannelData.hpp"
#include "sensor.hpp"
//#include "gesture.hpp"
#include "decision.hpp"
#include "arm.hpp"

int mode_select(saved_channel_data, sensorClass::sensorReturnOutput, int currentRoverMode);
decision::decisionReturnPercent mode_disarmed(saved_channel_data, sensorClass::sensorReturnOutput);
decision::decisionReturnPercent mode_joystick_drive(saved_channel_data, sensorClass::sensorReturnOutput);
decision::decisionReturnPercent mode_joystick_grip(saved_channel_data, sensorClass::sensorReturnOutput, armClass& arm);
decision::decisionReturnPercent mode_joystick_driveAvoid(saved_channel_data, sensorClass::sensorReturnOutput);
decision::decisionReturnPercent mode_sensorAvoid(saved_channel_data, sensorClass::sensorReturnOutput);

enum roverControlMode{
    disarmed = 0,
    joystickDrive,
    joystickGrip,
    //joystickDriveAvoid,
    sensorAvoid,
};
const int roverControlModeEnumLength = 3;
static int currentRoverMode = 0;
const int deadZoneMin = 400;
const int deadZoneMin2 = 100;
const int deadZoneMax = 500;
const int deadZoneMax2 = 900;
#endif