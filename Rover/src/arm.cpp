#include <arduino.h>
#include "arm.hpp"

void armClass::setup(){
    Serial.println("Arm setup");
    servo_yaw0.setup(yawPin, timer4);
    servo_pitch1.setup(pitchPin, timer2);
    servo_forwardBack2.setup(forwardBackPin, timer3);
    servo_grip3.setup(gripPin, timer1);
    delay(100);

    servo_yaw0.move(yawDefault);
    servo_pitch1 .move(pitchDefault);
    servo_forwardBack2.move(forwardBackDefault);
    servo_grip3.move(gripDefault);
}

void armClass::armTest(){
    Serial.println("Running arm test. Stand by.");
    delay(2000);
    // Serial.print("Yaw ");
    // servo_yaw0.move(160);
    // Serial.print("160 ");
    // delay(2000);
    // servo_yaw0.move(40);
    // Serial.print("40 ");
    // delay(2000);
    // servo_yaw0.move(90);
    // Serial.println("90");
    // delay(2000);

    // Serial.print("Pitch ");
    // servo_pitch1.move(140);
    // Serial.print("140 ");
    // delay(2000);
    // servo_pitch1.move(70);
    // Serial.println("70");
    // delay(2000);

    Serial.print("ForwardBack ");
    servo_forwardBack2.move(40);
    Serial.print("40 ");
    delay(2000);
    servo_forwardBack2.move(90);
    Serial.println("90");
    delay(2000);
    
    // Serial.print("Grip ");
    // servo_grip3.move(170);
    // Serial.print("170 ");
    // delay(2000);
    // servo_grip3.move(80);
    // Serial.println("80");
    // delay(2000);
    Serial.println("Arm test finished.");
}
    
void armClass::yaw(int target){
    servo_yaw0.move(target);
}

void armClass::pitch(int target){
    servo_pitch1.move(target);
}

void armClass::forwardBack(int target){
    servo_forwardBack2.move(target);
}

void armClass::grip(int target){
    servo_grip3.move(target);
}