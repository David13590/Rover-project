#ifndef DECISION_HPP_
#define DECISION_HPP_
#include "sensor.hpp"

class decision{
    public:
        struct decisionReturnPercent{
            int motorPercentLeft;
            int motorPercentRight;
        };
        decisionReturnPercent* get_decision();
    private:
        sensorClass mySensor;
        decisionReturnPercent myMotorPercent;
        int deadZoneMin = 400;
        int deadZoneMax = 500;
};
#endif