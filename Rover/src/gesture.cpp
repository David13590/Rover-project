#include <Arduino.h>
#include <Wire.h>
#include "gesture.hpp"

void gesture::gestureSetup(){
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(buttonPin, INPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Gesture setup complete");
}

bool gesture::readGesture(){
    static int state = 0;
    static int startTime = 0;
    static int endTime = 0;
    static int lastTime = 0;
    bool senseGesture = digitalRead(buttonPin);
    bool gesture = false;
    digitalWrite(LED_BUILTIN, senseGesture);

    if(state == 0){
        if(senseGesture == HIGH){
            state = 1;
            startTime = millis();
        }
    }
    if(state == 1){
        if(senseGesture == HIGH){
            lastTime = millis();
        }
        if(lastTime - startTime > 200){
            Serial.print("gesture");
            gesture = true;
            state = 2;
        }
    } 
    if(state == 2){
        if(senseGesture == HIGH){
            lastTime = millis();
        }
        else{
            endTime = millis();
        }
        if(endTime - lastTime > 500){
            state = 0;
        }
    } 
    return gesture;   
}