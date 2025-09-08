#include <Arduino.h>

// H-bro pins
const int motorIn1 = 18;
const int motorIn2 = 19;

// ACS712 pin
const int currentSensorPin = 34; // Analog pin (ESP32 ADC)

// Konstanter
const float VREF = 3.3;           // ESP32 ADC reference
const int ADC_RES = 4096;         // 12-bit opløsning
const float sensitivity = 0.185;  // V/A for ACS712 5A

// Offset (måles i setup)
int rawOffset = 2048;

void calibrateCurrentSensor() {
  long sum = 0;
  const int samples = 100;
  Serial.println("Kalibrerer strømsensor...");

  // Kalibrér når motoren er slukket
  for (int i = 0; i < samples; i++) {
    sum += analogRead(currentSensorPin);
    delay(10);
  }
  rawOffset = sum / samples;
  Serial.print("Kalibreret offset: ");
  Serial.println(rawOffset);
}

void setup() {
  Serial.begin(115200);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  calibrateCurrentSensor();
}

void loop() {
  // Tænd motor (retning frem)
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);

  // Læs strøm
  int rawADC = analogRead(currentSensorPin);
  float voltage = rawADC * (VREF / ADC_RES);
  float current = ((rawADC - rawOffset) * (VREF / ADC_RES)) / sensitivity;

  Serial.print("Raw ADC: ");
  Serial.print(rawADC);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Current: ");
  Serial.print(current, 3);
  Serial.println(" A   motor ON");
  delay(2000);

  // Sluk motor
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  delay(100);

  // Læs strøm igen
  rawADC = analogRead(currentSensorPin);
  voltage = rawADC * (VREF / ADC_RES);
  current = ((rawADC - rawOffset) * (VREF / ADC_RES)) / sensitivity;

  Serial.print("Raw ADC: ");
  Serial.print(rawADC);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Current: ");
  Serial.print(current, 3);
  Serial.println(" A   motor OFF");

  delay(2000);
}
