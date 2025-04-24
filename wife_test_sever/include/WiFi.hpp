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
    // 初始化串口通信
   // Serial.begin(115200);
    
    // 连接到 WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    oled_show_char("Connecting to WiFi...",0,1);
    }
    oled_show_char("Connected to WiFi",0,1);

    // 启动服务器
    server.begin();
    oled_show_char("Server started",0,1);
}
#endif