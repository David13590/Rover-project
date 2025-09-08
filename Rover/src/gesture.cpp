#include <Arduino.h>
#include <Wire.h>
#include "gesture.hpp"

void gesture::gestureSetup(){
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(buttonPin, INPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Gesture setup complete");
}
<<<<<<< HEAD:Blink_LED/src/gesture.cpp
 
bool gesture(){
=======

bool gesture::readGesture(){
    static int state = 0;
>>>>>>> origin/Joystick-control-wip:Rover/src/gesture.cpp
    static int startTime = 0;
    static int endTime = 0;
    static int lastTime = 0;
    bool senseGesture = digitalRead(buttonPin);
    bool gesture = false;
    digitalWrite(LED_BUILTIN, senseGesture);

<<<<<<< HEAD:Blink_LED/src/gesture.cpp
    enum gestureStates{
        gestureFirstHigh = 0,
        gestureStillHigh,
        gestureLow
    };
    gestureStates mystate = gestureFirstHigh;
    switch (mystate){
    case gestureFirstHigh:
        if(senseGesture == HIGH){ //Ved første observeing af HIGH, begynd at tag tid med startTime
=======
    if(state == 0){ //wait for trig
        if(senseGesture == HIGH){
            state = 1;
>>>>>>> origin/Joystick-control-wip:Rover/src/gesture.cpp
            startTime = millis();
            mystate = gestureStillHigh;
        }
<<<<<<< HEAD:Blink_LED/src/gesture.cpp
        break;
    case gestureStillHigh:
        if(senseGesture == HIGH){ //Hvis gesture stadig er høj, lastTime bliver gemt
            lastTime = millis();
        }
        if(lastTime - startTime > 200){ //Hvis forskellen mellem lastTime og startTime bliver større end 200ms
            gesture = true;             //så er det en "gesture"
            mystate = gestureLow;
        }
        break;
    case gestureLow:
        if(senseGesture == HIGH){ //
=======
    }
    if(state == 1){ //Signal active debounce wait
        if(senseGesture == HIGH){
            lastTime = millis();
        }
        if(lastTime - startTime > 200){
            Serial.print("gesture");
            gesture = true;
            state = 2;
        }
    } 
    if(state == 2){ //Signal inacitve reset trig wait 
        if(senseGesture == HIGH){
>>>>>>> origin/Joystick-control-wip:Rover/src/gesture.cpp
            lastTime = millis();
        }
        else{
            endTime = millis(); //Hvis senseGesture er lav gem endTime for gesture
        }
<<<<<<< HEAD:Blink_LED/src/gesture.cpp

        if(endTime - lastTime > 500){ //Når forskellen mellem endTime og lastTime er større end 500ms 
            mystate = gestureFirstHigh;                //kan man give en ny gesture
        }
        break;
    }
    Serial.print(mystate);
=======
        if(endTime - lastTime > 500){
            state = 0;
        }
    } 
>>>>>>> origin/Joystick-control-wip:Rover/src/gesture.cpp
    return gesture;   
}