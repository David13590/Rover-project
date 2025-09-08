#include <DHT.h>    

#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(115200);
dht.begin();
}
void loop() {
float humidity = dht.readHumidity();
float temperature = dht.readTemperature();
float dewpoint = (temperature-(100-humidity)/5);

if (humidity > 80){
    Serial.print("High luft fugtighed!!   ");
}

Serial.print("Fugtighed: ");
Serial.print(humidity);
Serial.print("%  ");
Serial.print("Temperatur: ");
Serial.print(temperature);
Serial.print(" °C");
Serial.print(" Dugpunkt: ");
Serial.println(dewpoint);
delay(2000);
}
