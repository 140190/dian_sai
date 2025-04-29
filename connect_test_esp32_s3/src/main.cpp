#include <HardwareSerial.h>
#include <Arduino.h>
#include "screen.hpp"

// 自定义引脚，要和发送端对应
const int txPin = 17;
const int rxPin = 16;

void setup() {
  // 初始化UART1，波特率115200
  oled_init();
  Serial1.begin(115200, SERIAL_8N1, rxPin, txPin);
  while (!Serial1);
 
}

void loop() {
  // 检查是否有可用数据
  if (Serial1.available()) {
    // 读取串口数据
    if(Serial1.read() == 0x01){
      Serial1.write(0x01);
      oled_show_char("stop", 0, 1);
    }
  }
  else{
    oled_show_char("start", 0, 1); 
  }
}