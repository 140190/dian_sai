


// put function declarations here:
#include "screen.hpp"
#include "WiFi.hpp"




char text[30];
uint8_t i=0;
void setup() {
  oled_init();
  Serial.begin(9800);

  wifi_init();
}

void loop() {
  //清空缓冲区
  // 等待客户端连接
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    while (client.connected()) {
      if (client.available()) {
        String line = client.readStringUntil('\n');
        Serial.println("Received: " + line);
        // 向客户端发送响应
        client.println("Message received");
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}