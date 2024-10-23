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
    bool senseGesture = digitalRead(buttonPin);
    bool gesture = false;
    digitalWrite(LED_BUILTIN, senseGesture);

    enum gestureStates{
        gestureFirstHigh = 0,
        gestureStillHigh,
        gestureLow
    };
    gestureStates mystate = gestureFirstHigh;
    switch (mystate){
    case gestureFirstHigh:
        if(senseGesture == HIGH){ //Ved første observeing af HIGH, begynd at tag tid med startTime
            startTime = millis();
            mystate = gestureStillHigh;
        }
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
            lastTime = millis();
        }
        else{
            endTime = millis(); //Hvis senseGesture er lav gem endTime for gesture
        }

        if(endTime - lastTime > 500){ //Når forskellen mellem endTime og lastTime er større end 500ms 
            mystate = gestureFirstHigh;                //kan man give en ny gesture
        }
        break;
    }
    Serial.print(mystate);
    return gesture;   
}