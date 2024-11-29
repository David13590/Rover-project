#include <arduino.h>
#include "joystick.hpp"

void joystick::setup(){
    
}

static joystick::joystickValue myJoystickValue; //Creates instance of struct
joystick::joystickValue* joystick::get_value(int joyXPin, int joyYPin){
    
    //Read joystick value
    int joystickX = analogRead(joyXPin); 
    int joystickY = analogRead(joyYPin);

    return 
}