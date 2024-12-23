#include <arduino.h>
#include "motor.hpp"
#include "decision.hpp"

void motor::motorSetup(){ 
    int motorPins[] = {motorFL1, motorFR1, motorFL2, motorFR2, motorBL1, motorBL2, motorBR1, motorBR2};
    int motorPinArrayLen = sizeof(motorPins)/sizeof(motorPins[0]); //Finder længden af pins array, sætter pins i array som output
    for(int i=0; i < motorPinArrayLen; i++){
        pinMode(motorPins[i], OUTPUT);
        analogWrite(motorPins[i], 0);
    }
    Serial.print("Motor setup complete");
}

//Motor check for at se om motore virker og sidder rigtigt.
void motor::motorCheck(){
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
    delay(1000);
}

  //decision percent 0, 25,  50,  75,  100   
int motorSpeeds[] = {0, 160, 180, 200, 255};
void motor::SetLeftMotorsSpeedForward(int speed){ //hastighed 0 1 2 eller 3 fra motorSpeeds array
    analogWrite(motorFL1, motorSpeeds[speed]);
    analogWrite(motorBL1, motorSpeeds[speed]);
}

void motor::SetRightMotorsSpeedForward(int speed){
    analogWrite(motorFR1, motorSpeeds[speed]);
    analogWrite(motorBR1, motorSpeeds[speed]);
}

void motor::SetLeftMotorsSpeedBackward(int speed){
    analogWrite(motorFL2, motorSpeeds[speed]);
    analogWrite(motorBL2, motorSpeeds[speed]);
}

void motor::SetRightMotorsSpeedBackward(int speed){
    analogWrite(motorFR2, motorSpeeds[speed]);
    analogWrite(motorBR2, motorSpeeds[speed]);
}

void motor::stopMotors(){
    analogWrite(motorFL1, motorSpeeds[0]);
    analogWrite(motorBL1, motorSpeeds[0]);

    analogWrite(motorFR1, motorSpeeds[0]);
    analogWrite(motorBR1, motorSpeeds[0]);
}

void motor::runMotors(){
    decision::decisionReturnPercent* myMotorPercent = myDecision.get_decision();

    //FORWARD: right motors
    if (myMotorPercent->motorPercentLeft == 0){
        SetRightMotorsSpeedForward(0); // 0 stop højre
    }
    else if (myMotorPercent->motorPercentLeft > 1){
        SetRightMotorsSpeedForward(1); // 25 procent fart
    }
    else if (myMotorPercent->motorPercentLeft > 25 ){
        SetRightMotorsSpeedForward(2); // 50
    }
    else if (myMotorPercent->motorPercentLeft > 50){
        SetRightMotorsSpeedForward(3); // 75
    }
    else if (myMotorPercent->motorPercentLeft > 75){
        SetRightMotorsSpeedForward(4);// 100 Full speed ahead!!
    } 

    //FORWARD: left motors
    if (myMotorPercent->motorPercentRight == 0){
        SetLeftMotorsSpeedForward(0);
    }
    else if (myMotorPercent->motorPercentRight > 1){
        SetLeftMotorsSpeedForward(1);
    }
    else if (myMotorPercent->motorPercentRight > 25){
        SetLeftMotorsSpeedForward(2);
    }
    else if (myMotorPercent->motorPercentRight > 50){
        SetLeftMotorsSpeedForward(3);
    }
    else if (myMotorPercent->motorPercentRight > 75){
        SetLeftMotorsSpeedForward(4);
    }

    //BACKWARD: Joystick
    if (myMotorPercent->motorPercentLeft < -1){
        SetRightMotorsSpeedBackward(1);
    }
    else if (myMotorPercent->motorPercentLeft < -25){
        SetRightMotorsSpeedBackward(2);
    }
    else if (myMotorPercent->motorPercentLeft < -50){
        SetRightMotorsSpeedBackward(3);
    }
    else if (myMotorPercent->motorPercentLeft < -75){
        SetRightMotorsSpeedBackward(4);
    } 

    //BACKWARD: Joystick
    if (myMotorPercent->motorPercentRight < -1){
        SetLeftMotorsSpeedBackward(1);
    }
    else if (myMotorPercent->motorPercentRight < -25){
        SetLeftMotorsSpeedBackward(2);
    }
    else if (myMotorPercent->motorPercentRight < -50){
        SetLeftMotorsSpeedBackward(3);
    }
    else if (myMotorPercent->motorPercentRight < -75){
        SetLeftMotorsSpeedBackward(4);
    }
}