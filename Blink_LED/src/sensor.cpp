#include <arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "sensor.hpp"


VL53L0X sensor;
VL53L0X sensor2;

void sensorSetup(){
    Serial.print("Running sensor setup. Stand by.\n");
    
    pinMode(XshutSensor1, OUTPUT);
    pinMode(XshutSensor2, OUTPUT);

    //Sluk alle sensors
    digitalWrite(XshutSensor1, LOW);//active low
    digitalWrite(XshutSensor2, LOW);

    Serial.begin(115200);
    Wire.begin();
    
    //Tænd sensor1
    digitalWrite(XshutSensor1, HIGH); //Tænd en efter en og sæt adresse
    delay(150);
    sensor.init(true);
    sensor.setAddress((uint8_t)01); //Ny adresse

    //Tænd sensor2
    digitalWrite(XshutSensor2, HIGH);
    delay(150);
    sensor2.init(true);
    sensor2.setAddress((uint8_t)02); 

    sensor.startContinuous();
    sensor2.startContinuous();

    Serial.print("Sensor setup complete. \n");
    
}

static sensorReturnOutput mySensorOutput;
sensorReturnOutput* sensorRead(){
    int distanceLeft = sensor.readRangeContinuousMillimeters();
    int distanceRight = sensor2.readRangeContinuousMillimeters();

    Serial.print("DistanceLeft: ");
    Serial.print(distanceLeft);
    Serial.print("mm ");
    
    Serial.print("DistanceRight: ");
    Serial.print(distanceRight);
    Serial.print("mm ");

mySensorOutput.sensorDistanceLeft = distanceLeft;
mySensorOutput.sensorDistanceRight = distanceRight;
return &mySensorOutput;
    
}

