#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;

void setup(){
Serial.begin(9600);
Wire.begin();
sensor.init();

sensor.setTimeout(100);
sensor.startContinuous();

}
void loop(){
    int distance = sensor.readRangeContinuousMillimeters();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("mm");
    if (sensor.timeoutOccurred()) { Serial.print(0); }
    Serial.println();
    delay(100);
}