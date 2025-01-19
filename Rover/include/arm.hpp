#ifndef ARM_HPP_
#define ARM_HPP_
#include "servo.hpp"
class armClass{
    private:
        servoClass servo_yaw0;
        servoClass servo_pitch1;
        servoClass servo_forwardBack2;
        servoClass servo_grip3;
        const int yawDefault = 90, pitchDefault = 100, forwardBackDefault = 90, gripDefault = 180;
        int yawPin = 17,  pitchPin = 4,   forwardBackPin = 16, gripPin = 23;
        int timer1 = 0, timer2 = 1, timer3 = 2, timer4 = 3;

    public:
        const int yawMax = 180, pitchMax = 175, forwardBackMax = 200,   gripMax = 180;
        const int yawMin = 0,   pitchMin = 50,  forwardBackMin = 86,   gripMin = 81;
        int yawCurrentPos = yawDefault;
        int pitchCurrentPos = pitchDefault;
        int forwardBackCurrentPos = forwardBackDefault;
        int gripCurrentPos = gripDefault;
        const int increment = 2;
        const int decrement = -2;
        void setup();
        void armTest();
        void yaw(int target);
        void pitch(int target);
        void forwardBack(int target);
        void grip(int target);

};
#endif