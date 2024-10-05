#include <arduino.h>
#include "motor.hpp"


int motorSpeeds[] = {0, 170, 200, 255};

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

