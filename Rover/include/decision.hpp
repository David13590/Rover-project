#ifndef DECISION_HPP_
#define DECISION_HPP_
#include "sensor.hpp"
#include "arm.hpp"
//#include "gesture.hpp"

class decision{
    public:
        struct decisionReturnPercent{
            int motorPercentLeft;
            int motorPercentRight;
            int servoYawTarget;
            int servoPitchTarget;
            int servoForwardBackTarget;
            int servoGripTarget;
        };
        decision(armClass& Arm);
        decisionReturnPercent* get_decision();
    private:
        armClass& myArm;
        sensorClass mySensor;
        decisionReturnPercent myMotorPercent;
        //gesture decisionGesture;
        
};
#endif