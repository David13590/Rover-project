#ifndef SERVO_HPP_
#define SERVO_HPP_
#include <ESP32Servo.h>

class servoClass{
    private:
        Servo myServo;
       
    public:
        void setup(int servoPin, int servoTimerNumber);
        void servo_move(int target);
};
#endif