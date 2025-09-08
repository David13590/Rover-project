#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
void setup() {
 Serial.begin(115200);
 sensors.begin();
}
void loop() {
 sensors.requestTemperatures();
 float temperature = sensors.getTempCByIndex(0);
 Serial.print("DS18B20 Temp: ");
 Serial.print(temperature);
 Serial.println(" °C");
 delay(1000);
}
