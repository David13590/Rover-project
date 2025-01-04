#include <Arduino.h>
#include "savedChannelData.hpp"
#include "buttonModeSwitch.hpp"

bool buttonSwitchDetect(saved_channel_data joystick_data){
    static int state = 0;
    static int startTime = 0;
    static int endTime = 0;
    static int lastTime = 0;
    bool controllerButtonPress = false;
    bool buttonsPressed = joystick_data.pcbLeftButton == false && joystick_data.pcbRightButton == false;
    if(state == 0){
        if(buttonsPressed == true){
            state = 1;
            startTime = millis();  
        }
    }
    if(state == 1){
        if(buttonsPressed == true){
            lastTime = millis();
        }
        if(lastTime - startTime > 200){
            controllerButtonPress = true;
            state = 2;
        }
    }
    if(state == 2){
        if(buttonsPressed == true){
            lastTime = millis();
        }
        else{
            endTime = millis();
        }
        if(endTime - lastTime > 500){
            state = 0;
        }
    }
    return controllerButtonPress;
}