#include <Arduino.h>

#define LED_GREEN 16
#define LED_YELLOW 5
#define LED_RED 17

void setup() {
    Serial.begin(115200);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);

}

void loop() {
    //Red light
    analogWrite(LED_RED, 255);
    analogWrite(LED_GREEN, 0);
    delay(6000);

    //Yellow light
    analogWrite(LED_RED, 0);
    analogWrite(LED_YELLOW, 255);
    delay(1500);

    //Green light
    analogWrite(LED_RED, 0);
    analogWrite(LED_YELLOW, 0);
    analogWrite(LED_GREEN, 255);
    delay(5000);
    
}
