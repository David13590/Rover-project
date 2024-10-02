#ifndef MOTOR_HPP_
#define MOTOR_HPP_

//Forreste venstre motor
#define motorFL1 4
#define motorFL2 2

//Forreste højre motor
#define motorFR1 5
#define motorFR2 18

//Bagerste venstre motor
#define motorBL1 25
#define motorBL2 26

//Bagerste højre motor
#define motorBR1 14
#define motorBR2 27


void SetLeftMotorsSpeed(int speed);
void SetRightMotorsSpeed(int speeds);
void stopMotors();

#endif