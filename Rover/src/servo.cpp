#include <arduino.h>
#include <ESP32Servo.h>
#include "servo.hpp"

void servoClass::setup(int pin, int timerNumber){
    //Set ms range and attach to pins
    myServo.setPeriodHertz(50);
	myServo.attach(pin, 1000, 2000);
    ESP32PWM::allocateTimer(timerNumber);
}

void servoClass::move(int target){
    myServo.write(target);
}