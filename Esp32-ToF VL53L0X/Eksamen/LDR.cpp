#include <Arduino.h>
#define LDR_PIN 35       // Analog input pin (A0)
#define LED_PIN 17       // Digital output pin til LED

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);  // 0–4095
  Serial.print("Lysværdi: ");
  Serial.println(ldrValue);

  //Simpelt mørkedetekt – skift tærskel efter behov
  if (ldrValue > 3500) {
    analogWrite(LED_PIN, 255);
  }
  else if (ldrValue > 3300) {
    analogWrite(LED_PIN, 125);
  }
  else if (ldrValue > 3000) {
    analogWrite(LED_PIN, 50);
  }
  else if (ldrValue > 2900) {
    analogWrite(LED_PIN, 0);
  }    

  delay(500);
}
