#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
//Forreste venstre motor
#define motorFL1 5 
#define motorFL2 18

//Forreste højre motor
#define motorFR1 2 
#define motorFR2 4

#define LED 17

int pins[] = {LED, motorFL1, motorFL2, motorFR1, motorFR2}; //Pins der skal sættes som output
int motorSpeeds[] = {0, 120, 160, 255};

void setup()
{

  Serial.begin(115200);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  int pinArrayLen = sizeof(pins)/sizeof(pins[0]);
  for(int i; i < pinArrayLen; i++){
    pinMode(pins[i], OUTPUT);
    analogWrite(pins[i], 0);
  }


}

void loop()
{
  int distance = sensor.readRangeContinuousMillimeters();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm");

  //if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  
  if (distance <= 400){
    analogWrite(motorFL1, motorSpeeds[3]);
    analogWrite(motorFR1, motorSpeeds[3]);
    analogWrite(LED, 255);
  }
  else if (distance > 400){
    analogWrite(motorFL1, motorSpeeds[0]);
    analogWrite(motorFR1, motorSpeeds[0]);
    analogWrite(LED, 0);
  }

  Serial.println();
  delay(1);
}