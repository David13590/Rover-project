#include <Arduino.h>
#include <Wire.h>
#include "gesture.hpp"

void gestureSetup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}
 


bool gesture(){
    static int state = 0;
    static int startTime = 0;
    static int endTime = 0;
    static int lastTime = 0;
    bool i = digitalRead(buttonPin);
    bool gesture = false;
    digitalWrite(LED_BUILTIN, i);

    if(state == 0){
        if(i == HIGH){
            state = 1;
            startTime = millis();
        }
    }

    if(state == 1){
        if(i == HIGH){
            lastTime = millis();
        }
        if(lastTime - startTime > 200){
            gesture = true;
            state = 2;
        }
    } 

    if(state == 2){
        if(i == HIGH){
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