#ifndef MOTOR_HPP_
#define MOTOR_HPP_

//Forreste venstre motor
#define motorFL1 25
#define motorFL2 26

//Forreste højre motor
#define motorFR1 5
#define motorFR2 18

//Bagerste venstre motor
#define motorBL1 27
#define motorBL2 14

//Bagerste højre motor
#define motorBR1 3
#define motorBR2 19


void SetLeftMotorsSpeed(int speed);
void SetRightMotorsSpeed(int speeds);
void stopMotors();
void motorSetup();
void runMotors();
void motorCheck();

#endif