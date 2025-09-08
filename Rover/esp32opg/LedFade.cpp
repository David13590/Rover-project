#include <Arduino.h>

#define LED 17
int brightness = 0;
int fadeAmount = 1;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
analogWrite(LED, brightness);
brightness = brightness + fadeAmount;
if(brightness <= 0 || brightness >= 150){
  fadeAmount = -fadeAmount;
}
delay(30);
}