#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <ezButton.h>
#include "controllerSender.hpp"
#include "joystick.hpp"

controllerSender controllerConfig;
joystick joystickLeft;
joystick joystickRight;
ezButton joyLeftButton(JOY_LEFT_SW_PIN);
ezButton joyRightButton(JOY_RIGHT_SW_PIN);

//Receiver Test: 0xd0, 0xef, 0x76, 0xf0, 0x11, 0xd8
//Sender Test: 0xd0, 0xef, 0x76, 0xef, 0xed, 0x10
//Rover: 0xd0, 0xef, 0x76, 0xee, 0xef, 0xa8
uint8_t broadcastAddress[] = {0xd0, 0xef, 0x76, 0xf0, 0x11, 0xd8}; 
const int joystickMaxRead = 4095;

// Create a channel_data for sender
controllerSender::channel_data channelValue;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status: ");
  Serial.print(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  pinMode(pcbButtonLeft, INPUT_PULLUP);
  pinMode(pcbButtonRight, INPUT_PULLUP);
  joystickLeft.setup(JOY_LEFT_VRX_PIN, JOY_LEFT_VRY_PIN, JOY_LEFT_SW_PIN);
  joystickRight.setup(JOY_RIGHT_VRX_PIN, JOY_RIGHT_VRY_PIN, JOY_RIGHT_SW_PIN);

  // Init Serial Monitor
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db);
  joyLeftButton.setDebounceTime(controllerConfig.buttonDebounceTime);
  joyRightButton.setDebounceTime(controllerConfig.buttonDebounceTime);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.print("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.print(" Failed to add peer");
    return;
  }
}

int testValues[] = {0, 1850, 4095};
int testValueCounter = 0;
void loop() {
  // Set values to send
  joystick::joystickValue myjoystickvalueLeft{};
  joystick::joystickValue myjoystickvalueRight{};

  if(testValueCounter == 0){
    myjoystickvalueLeft.x = testValues[testValueCounter];
    testValueCounter = 1;
  }
  if(testValueCounter == 1){
    myjoystickvalueLeft.x = testValues[testValueCounter];
    testValueCounter = 2;
  }
  if(testValueCounter == 2){
    myjoystickvalueLeft.x = testValues[testValueCounter];
    testValueCounter = 0;
  }

  
  myjoystickvalueLeft.x = map(myjoystickvalueLeft.x, controllerConfig.mapFromLow, controllerConfig.mapFromHigh, controllerConfig.mapToLow, controllerConfig.mapToHigh);
  myjoystickvalueLeft.y = map(myjoystickvalueLeft.y, controllerConfig.mapFromLow, controllerConfig.mapFromHigh, controllerConfig.mapToLow, controllerConfig.mapToHigh);
  myjoystickvalueRight.x = map(myjoystickvalueRight.x, controllerConfig.mapFromLow, controllerConfig.mapFromHigh, controllerConfig.mapToLow, controllerConfig.mapToHigh);
  myjoystickvalueRight.y = map(myjoystickvalueRight.y, controllerConfig.mapFromLow, controllerConfig.mapFromHigh, controllerConfig.mapToLow, controllerConfig.mapToHigh);
  joyLeftButton.loop(); 
  joyRightButton.loop();
  channelValue.channel1 = myjoystickvalueLeft.x;
  channelValue.channel2 = myjoystickvalueLeft.y;
  channelValue.channel3 = myjoystickvalueLeft.button;
  channelValue.channel4 = myjoystickvalueRight.x;
  channelValue.channel5 = myjoystickvalueRight.y;
  channelValue.channel6 = myjoystickvalueRight.button;
  channelValue.channel7 = digitalRead(pcbButtonLeft);
  channelValue.channel8 = digitalRead(pcbButtonRight);
  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &channelValue, sizeof(channelValue));
   
  if (result != ESP_OK) {
    Serial.print(", Error sending the data");
  }
  Serial.print("\t joy1x: ");
  Serial.print(channelValue.channel1);
  Serial.print(" joy1y: ");
  Serial.print(channelValue.channel2);
  Serial.print(" knap1: ");
  Serial.print(channelValue.channel3);
  Serial.print("\t joy2x: ");
  Serial.print(channelValue.channel4);
  Serial.print(" joy2y: ");
  Serial.print(channelValue.channel5);
  Serial.print(" knap2: ");
  Serial.print(channelValue.channel6);
  Serial.print(" buttonPCBLeft: ");
  Serial.print(channelValue.channel7);
  delay(1000);
}