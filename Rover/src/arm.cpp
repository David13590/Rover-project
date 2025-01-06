#include <arduino.h>
#include "arm.hpp"

void armClass::setup(){
    servo_yaw0.setup(yawPin, timer1);
    // servo_pitch1.setup(pitchPin, timer2);
    // servo_forwardBack2.setup(forwardBackPin, timer3);
    // servo_grip3.setup(gripPin, timer4);
}

void armClass::armTest(){
    Serial.print("Running arm test. Stand by.");
    delay(3000);
    servo_yaw0.servo_move(180);
    Serial.print("180");
    delay(2000);
    servo_yaw0.servo_move(90);
    Serial.print("90");
    delay(2000);
    servo_yaw0.servo_move(0);
    Serial.print("0");
    delay(2000);
    servo_yaw0.servo_move(90);
    Serial.print("90");
    delay(2000);
    Serial.println("Arm test finished.");
}
    
void armClass::yaw(){
    servo_yaw0.servo_move(180);
}

void armClass::pitch(){
    servo_pitch1.servo_move(180);
}

void armClass::forwardBack(){
    servo_forwardBack2.servo_move(180);
}

void armClass::grip(){
    servo_grip3.servo_move(180);
}