//#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

float pressure;   //To store the barometric pressure (Pa)
float temperature;  //To store the temperature (oC)
int altimeter;

void setup(void) {
  Serial.begin(115200);
  bmp.begin(0x76);
  delay(100);
}

void loop() {
pressure = bmp.readPressure();
temperature = bmp.readTemperature();
altimeter = bmp.readAltitude (1050.35);

  Serial.print(F("Pressure: "));
    Serial.print(pressure);
    Serial.print(" Pa");
    Serial.print("\t");
    Serial.print(("Temp: "));
    Serial.print(temperature);
    Serial.print(" °C");
  Serial.print("\t");
    Serial.print("Altimeter: ");
    Serial.print(altimeter); // this should be adjusted to your local forcase
    Serial.println(" m");
  Serial.print("");
  
  delay(1000);
}
