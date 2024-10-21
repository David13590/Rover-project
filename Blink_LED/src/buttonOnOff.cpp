#include <Arduino.h>
#include "buttonOnOff.hpp"

int buttonState = 0;
int lastButtonState = 0;

void buttonOnOffSetup(){
    pinMode(buttonPin, INPUT_PULLDOWN);
}

bool buttonOnOff(){
    buttonState = digitalRead(buttonPin);
    if(buttonState != lastButtonState){
        if (buttonState == 1){
            Serial.print("ON"); 
            Serial.println(buttonState);
            return true;
        }
        else{
            Serial.print("OFF ");
            Serial.println(buttonState);
            return false;
        }

        delay(50);
    }

    lastButtonState = buttonState;   
}