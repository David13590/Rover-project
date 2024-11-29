#include <esp_now.h>
#include <WiFi.h>
#include <wire.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    int x;
    int y;
    float xvolt;
    float yvolt;
    bool button;
} struct_message;

// Create a struct_message called myData
struct_message myJoystickValues;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myJoystickValues, incomingData, sizeof(myJoystickValues));
  Serial.print(myJoystickValues.x);
  Serial.print(" joy1y: ");
  Serial.print(myJoystickValues.y);
  Serial.print(" knap: ");
  Serial.println(myJoystickValues.button);
  Serial.print(" joy1x: ");
  Serial.print(myJoystickValues.xvolt);
  Serial.print(" xvolt ");
  Serial.print(myJoystickValues.yvolt);
  Serial.print(" yvolt ");
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