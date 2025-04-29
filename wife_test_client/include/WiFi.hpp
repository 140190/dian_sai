#ifndef WiFi_hpp
#define WiFi_hpp
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include "screen.hpp"
const char* ssid = "Xiaomi13";
const char* password = "flj820412";
WiFiServer server(80);
void wifi_init() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}
#endif