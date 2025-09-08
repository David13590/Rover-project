#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
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

#define LED 17

//Pins der skal sættes som output
int pins[] = {LED, motorFL1, motorFL2, motorFR1, motorFR2, motorBL1, motorBL2, motorBR1, motorBR2}; 
int motorSpeeds[] = {0, 150, 190, 255};
int reactDistance = 50; //Distance hvis sensor læser noget under, drej.

void setup(){
  Serial.begin(115200);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  //Finder længden af pins array, sætter pins i array som digital eller analog output
  int pinArrayLen = sizeof(pins)/sizeof(pins[0]);
  for(int i; i < pinArrayLen; i++){
    pinMode(pins[i], OUTPUT);
    analogWrite(pins[i], 0);
  }

}

void SetLeftMotorsSpeed(int speed){ //hastighed 0 1 2 eller 3 fra motorSpeeds array
  analogWrite(motorFL1, motorSpeeds[speed]);
  analogWrite(motorBL1, motorSpeeds[speed]);
  
}

void SetRightMotorsSpeed(int motorSpeeds[], int time){


}

void stopMotors(){
  analogWrite(motorFL1, motorSpeeds[0]);
  analogWrite(motorBL1, motorSpeeds[0]);

  analogWrite(motorFR1, motorSpeeds[0]);
  analogWrite(motorBR1, motorSpeeds[0]);
}

void loop(){
  int distance = sensor.readRangeContinuousMillimeters();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm ");
  
  
  if (distance <= reactDistance){
    //kør langsommere på højre / drej venstre
    SetLeftMotorsSpeed(1);
    //analogWrite(motorFL1, motorSpeeds[3]);
    //analogWrite(motorBL1, motorSpeeds[3]);

    //analogWrite(motorFR1, motorSpeeds[1]);
    //analogWrite(motorBR1, motorSpeeds[1]);

    analogWrite(LED, 255);
  }
  else if (distance > reactDistance){
    //kør alle motore
    // analogWrite(motorFL1, motorSpeeds[3]);
    // analogWrite(motorBL1, motorSpeeds[3]);

    // analogWrite(motorFR1, motorSpeeds[3]);
    // analogWrite(motorBR1, motorSpeeds[3]);
    
    stopMotors();
    analogWrite(LED, 0);
  }

  Serial.println();
  delay(1);

}