#include <esp_now.h>
#include <WiFi.h>
#include <wire.h>

// Structure example to receive data
// Must match the sender structure
typedef struct channel_data {
  int channel1;
  int channel2;
  bool channel3;
  int channel4;
  int channel5;
  bool channel6;
} channel_data;

// Create a struct_message called myData
channel_data channelValue;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
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
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

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

void loop() {
}