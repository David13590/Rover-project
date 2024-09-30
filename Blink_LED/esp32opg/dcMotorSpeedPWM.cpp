#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
//Forreste venstre motor
#define motorFL1 5 
#define motorFL2 18

//Forreste højre motor
#define motorFR1 12 
#define motorFR2 13

#define LED 17

int pins[] = {17}; //Pins der skal sættes som output
int motorSpeeds[] = {0, 120, 160, 255};

void setup()
{

  Serial.begin(115200);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  pinMode(LED, OUTPUT);
  pinMode(motorFL1, OUTPUT);
  pinMode(motorFL2, OUTPUT);
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
    digitalWrite(LED, HIGH);
  }
  else if (distance > 400){
    analogWrite(motorFL1, motorSpeeds[0]);
    digitalWrite(LED, LOW);
  }

  Serial.println();
  delay(1);
}