#include <esp_now.h>
#include <WiFi.h>
#include <wire.h>
#include "receiver.hpp"

typedef struct channel_data{
    int channel1;
    int channel2;
    bool channel3;
    int channel4;
    int channel5;
    bool channel6;
    bool channel7;
    bool channel8;
} channel_data;

// Create structs to save data
channel_data channelValue;
saved_channel_data saved_data;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&channelValue, incomingData, sizeof(channelValue));
  Serial.print(" 1X:");
  Serial.print(channelValue.channel1);
  Serial.print(" 1Y:");
  Serial.print(channelValue.channel2);
  Serial.print(" 1JB:");
  Serial.print(channelValue.channel3);
  Serial.print("   2X:");
  Serial.print(channelValue.channel4);
  Serial.print(" 2Y:");
  Serial.print(channelValue.channel5);
  Serial.print(" 2JB:");
  Serial.print(channelValue.channel6);
  Serial.print("  ");

  saved_data.joy1x = channelValue.channel1;
  saved_data.jo1y = channelValue.channel2;
  saved_data.joy1Button = channelValue.channel3;
  saved_data.joy2x = channelValue.channel4;
  saved_data.joy2y = channelValue.channel5;
  saved_data.joy2Button = channelValue.channel6;
  saved_data.pcbLeftButton = channelValue.channel7;
  saved_data.pcbRightButton = channelValue.channel8;
}

saved_channel_data& get_saved_channel_data(){
  return saved_data;
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