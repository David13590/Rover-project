#ifndef SWITCHMODE_HPP_
#define SWITCHMODE_HPP_
#include "savedChannelData.hpp"
#include "sensor.hpp"
#include "gesture.hpp"
#include "decision.hpp"

int mode_select(saved_channel_data, sensorClass::sensorReturnOutput, bool gesture);
decision::decisionReturnPercent mode_disarmed(saved_channel_data, sensorClass::sensorReturnOutput, bool gesture);
decision::decisionReturnPercent mode_joystick_drive(saved_channel_data, sensorClass::sensorReturnOutput, bool gesture);
decision::decisionReturnPercent mode_joystick_grip(saved_channel_data, sensorClass::sensorReturnOutput, bool gesture);
decision::decisionReturnPercent mode_joystick_driveAvoid(saved_channel_data, sensorClass::sensorReturnOutput, bool gesture);
decision::decisionReturnPercent mode_sensorAvoid(saved_channel_data, sensorClass::sensorReturnOutput, bool gesture);

enum roverControlMode{
    disarmed = 0,
    joystickDrive,
    joystickGrip,
    joystickDriveAvoid,
    sensorAvoid,
};
int roverControlModeEnumLength = 5;
static int currentRoverMode = 0;
int deadZoneMin = 400;
int deadZoneMax = 500;
#endif