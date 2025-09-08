#include <Arduino.h>

#define MQ2_PIN 4  // Analog pin på ESP32

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int sensorValue = analogRead(MQ2_PIN);
  Serial.print("MQ-2 analog værdi: ");
  Serial.println(sensorValue);
  delay(1000);
}
