#include <ESP32Servo.h>
#include <arduino.h>
#include <wire.h>

Servo myservo;
int pos = 0;
int servoPin = 17;
 
void setup() {
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);
	myservo.attach(servoPin, 500, 2400);
	Serial.begin(115200);
}
 
void loop() {
	pos = 25;
	myservo.write(pos);	 
	Serial.println(pos);
	delay(3000);
	
	pos = 100;        
	myservo.write(pos);    // tell servo to go to position in variable 'pos'
	Serial.println(pos);
	delay(3000);  // waits 15ms for the servo to reach the position
	
	pos = 160;
	myservo.write(pos);	 
	Serial.println(pos);
	delay(3000);

}