#include <arduino.h>
#include <ESP32Servo.h>
#include "servo.hpp"

void servoClass::setup(int pin, int timerNumber){
    //Set ms range and attach to pins
    myServo.setPeriodHertz(50);
	myServo.attach(pin, 1000, 2000);
    ESP32PWM::allocateTimer(timerNumber);
    // servo2Pitch.setPeriodHertz(50);
	// servo2Pitch.attach(pinServo2Pitch, 1000, 2000);
    // servo3ForwardBack.setPeriodHertz(50);
	// servo3ForwardBack.attach(pinServo3ForwardBack, 1000, 2000);
    // servo4Grip.setPeriodHertz(50);
	// servo4Grip.attach(pinServo4Grip, 1000, 2000);
}

void servoClass::move(int target){
    myServo.write(target);
}