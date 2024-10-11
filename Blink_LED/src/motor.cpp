#include <arduino.h>
#include "motor.hpp"
#include "decision.hpp"

void motorSetup(){
    
    int motorPins[] = {motorFL1, motorFR1, motorFL2, motorFR2, motorBL1, motorBL2, motorBR1, motorBR2};
    
    //Finder længden af pins array, sætter pins i array som analog output
    int motorPinArrayLen = sizeof(motorPins)/sizeof(motorPins[0]);
    for(int i=0; i < motorPinArrayLen; i++){
        pinMode(motorPins[i], OUTPUT);
        analogWrite(motorPins[i], 0);
    }

    
}

//Motor check for at se om motore virker og sidder rigtigt.
void motorCheck(){
    Serial.print("Running motor check. Stand by.\n");
    delay(2000);

    Serial.print("--Front Left--\n");
    analogWrite(motorFL1, 255);
    delay(2000);
    analogWrite(motorFL1, 0);

    Serial.print("--Front Right--\n");
    analogWrite(motorFR1, 255);
    delay(2000);
    analogWrite(motorFR1, 0);

    Serial.print("--Back Left--\n");
    analogWrite(motorBL1, 255);
    delay(2000);
    analogWrite(motorBL1, 0);

    Serial.print("--Back Right--\n");
    analogWrite(motorBR1, 255);
    delay(1000);
    analogWrite(motorBL1, 0);

    Serial.print("Motor check complete.");
    delay(2000);
}

  //decision percent 0, 25,  50,  75,  100   
int motorSpeeds[] = {0, 160, 180, 200, 255};
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

void runMotors(){
    decisionReturnPercent* myMotorPercent = decision();

    //Venstre sensor tæt. Styre højre motor sæt
    if (myMotorPercent->motorPercentLeft == 0){
        SetRightMotorsSpeed(0); // 0 stop højre
    }
    else if (myMotorPercent->motorPercentLeft > 0 && myMotorPercent->motorPercentLeft < 26){
        SetRightMotorsSpeed(1); // 25 procent fart
    }
    else if (myMotorPercent->motorPercentLeft > 25 && myMotorPercent->motorPercentLeft < 51){
        SetRightMotorsSpeed(2); // 50
    }
    else if (myMotorPercent->motorPercentLeft > 50 && myMotorPercent->motorPercentLeft < 76){
        SetRightMotorsSpeed(3); // 75
    }
    else if (myMotorPercent->motorPercentLeft > 75 && myMotorPercent->motorPercentLeft == 100){
        SetRightMotorsSpeed(4);// 100 Full speed ahead!!
    } 

    
    //Højre sensor tæt. Styre venstre motor sæt
    if (myMotorPercent->motorPercentRight == 0){
        SetLeftMotorsSpeed(0);
    }
    else if (myMotorPercent->motorPercentRight > 0 && myMotorPercent->motorPercentRight < 26){
        SetLeftMotorsSpeed(1);
    }
    else if (myMotorPercent->motorPercentRight > 25 && myMotorPercent->motorPercentRight < 51){
        SetLeftMotorsSpeed(2);
    }
    else if (myMotorPercent->motorPercentRight > 50 && myMotorPercent->motorPercentRight < 76){
        SetLeftMotorsSpeed(3);
    }
    else if (myMotorPercent->motorPercentRight > 75 && myMotorPercent->motorPercentRight == 100){
        SetLeftMotorsSpeed(4);
    }

}