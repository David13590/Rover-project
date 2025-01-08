#ifndef ARM_HPP_
#define ARM_HPP_
#include "servo.hpp"
class armClass{
    private:
        servoClass servo_yaw0;
        servoClass servo_pitch1;
        servoClass servo_forwardBack2;
        servoClass servo_grip3;
        const int yawDefault = 90, pitchDefault = 165, forwardBackDefault = 85, gripDefault = 81;
        //int yawMax = 180, pitchMax = 170, forwardBackMax = 50,   gripMax = 81;
        //int yawMin = 0,   pitchMin = 55,  forwardBackMin = 50,   gripMin = 81;
        int yawPin = 17,  pitchPin = 4,   forwardBackPin = 16 /*,   gripPin = 23*/;
        int timer1 = 0, timer2 = 1, timer3 = 2, timer4 = 3;

    public:
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