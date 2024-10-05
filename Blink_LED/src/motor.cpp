#include <arduino.h>
#include "motor.hpp"

void motorSetup(){
    
    int motorPins[] = {motorFR1, motorFL2, motorFL1, motorFR2, motorBL1, motorBL2, motorBR1, motorBR2};
    
    //Finder længden af pins array, sætter pins i array som analog output
    int motorPinArrayLen = sizeof(motorPins)/sizeof(motorPins[0]);
    for(int i=0; i < motorPinArrayLen; i++){
        pinMode(motorPins[i], OUTPUT);
        analogWrite(motorPins[i], 0);
    }
}

int motorSpeeds[] = {0, 160, 200, 255};
void SetLeftMotorsSpeed(int speed){ //hastighed 0 1 2 eller 3 fra motorSpeeds array
    analogWrite(motorFL1, motorSpeeds[speed]);
    analogWrite(motorBL1, motorSpeeds[speed]);
  
}

void SetRightMotorsSpeed(int speed){
    analogWrite(motorFR1, motorSpeeds[speed]);
    analogWrite(motorBR1, motorSpeeds[speed]);
}

void stopMotors(){
    analogWrite(motorFL1, motorSpeeds[0]);
    analogWrite(motorBL1, motorSpeeds[0]);

    analogWrite(motorFR1, motorSpeeds[0]);
    analogWrite(motorBR1, motorSpeeds[0]);
}