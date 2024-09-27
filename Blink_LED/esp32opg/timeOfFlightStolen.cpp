#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
#define LED 17

void setup()
{

  Serial.begin(9600);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  pinMode(LED, OUTPUT);
}

void loop()
{
  int distance = sensor.readRangeContinuousMillimeters();
  //int distance =sensor.startContinuous(100);
  
 //distance = distance;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm");
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  
  if (distance < 500){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }

  Serial.println();
  delay(100);
}