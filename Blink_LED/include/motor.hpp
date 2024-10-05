#ifndef MOTOR_HPP_
#define MOTOR_HPP_

//Forreste venstre motor
#define motorFL1 3
#define motorFL2 19

//Forreste højre motor
#define motorFR1 5
#define motorFR2 18

//Bagerste venstre motor
#define motorBL1 25
#define motorBL2 26

//Bagerste højre motor
#define motorBR1 27
#define motorBR2 14


void SetLeftMotorsSpeed(int speed);
void SetRightMotorsSpeed(int speeds);
void stopMotors();
void motorSetup();

#endif