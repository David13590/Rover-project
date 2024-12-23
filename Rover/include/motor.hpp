#ifndef MOTOR_HPP_
#define MOTOR_HPP_
#include "decision.hpp"

class motor{
    private:
        decision myDecision;

        //Forreste venstre motor
        #define motorFL1 25
        #define motorFL2 26

        //Forreste højre motor
        #define motorFR1 18
        #define motorFR2 5

        //Bagerste venstre motor
        #define motorBL1 27
        #define motorBL2 14

        //Bagerste højre motor
        #define motorBR1 19
        #define motorBR2 3

    public:
        void SetLeftMotorsSpeedForward(int speed);
        void SetRightMotorsSpeedForward(int speed);
        void SetLeftMotorsSpeedBackward(int speed);
        void SetRightMotorsSpeedBackward(int speed);
        void stopMotors();
        void motorSetup();
        void runMotors();
        void motorCheck();

};
#endif