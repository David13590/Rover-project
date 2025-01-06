#ifndef ARM_HPP_
#define ARM_HPP_
#include "servo.hpp"
class armClass{
    private:
        servoClass servo_yaw0;
        servoClass servo_pitch1;
        servoClass servo_forwardBack2;
        servoClass servo_grip3;
        int yawPin = 1;
        int pitchPin = 15;
        int forwardBackPin = 10;
        int gripPin = 23;
        int timer1 = 0, timer2 = 1, timer3 = 2, timer4 = 3;
    public:
        void setup();
        void armTest();
        void yaw();
        void pitch();
        void forwardBack();
        void grip();
};
#endif