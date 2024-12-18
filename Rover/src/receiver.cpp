#include <esp_now.h>
#include <WiFi.h>
#include <wire.h>
#include "receiver.hpp"

// Create structs to save data
channel_data channelValue;
saved_channel_data saved_data;

// callback function that will be executed when data is received
saved_channel_data* OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&channelValue, incomingData, sizeof(channelValue));
  Serial.print(" joy1x: ");
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
  Serial.println(channelValue.channel6);

  saved_data.channel1 = channelValue.channel1;
  saved_data.channel2 = channelValue.channel2;
  saved_data.channel3 = channelValue.channel3;
  saved_data.channel4 = channelValue.channel4;
  saved_data.channel5 = channelValue.channel5;
  saved_data.channel6 = channelValue.channel6;

  return &saved_data;
}

void receiver_setup() {
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}