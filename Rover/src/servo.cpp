#include <arduino.h>
#include <ESP32Servo.h>
#include "servo.hpp"

Servo myServo;
Servo servo2Pitch;
Servo servo3ForwardBack;
Servo servo4Grip;

void servoClass::setup(int pin){
    //Set ms range and attach to pins
    myServo.setPeriodHertz(50);
	myServo.attach(pin, 1000, 2000);
    
    // servo2Pitch.setPeriodHertz(50);
	// servo2Pitch.attach(pinServo2Pitch, 1000, 2000);
    // servo3ForwardBack.setPeriodHertz(50);
	// servo3ForwardBack.attach(pinServo3ForwardBack, 1000, 2000);
    // servo4Grip.setPeriodHertz(50);
	// servo4Grip.attach(pinServo4Grip, 1000, 2000);
    
    ESP32PWM::allocateTimer(0); 
	ESP32PWM::allocateTimer(1); 
	ESP32PWM::allocateTimer(2); 
	ESP32PWM::allocateTimer(3); 

}

void servoClass::servo_move(int target){
    static int joy1x = 90;
	static int joy1y = 90;
    static int joy2x = 90;
	static int joy2y = 90;

    //int target = 0; //Target should be a mapped value from joystick
    static int current = 0;
    for(current; current < target;){
        myServo.write(current+1);
    }

}