#ifndef TFT_HPP
#define TFT_HPP


#include <TFT_eSPI.h>
#include <Arduino.h>
#include <SPI.h>

#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
// 定义 HC - 06 的名称和密码
const char* Blue_Name = "ESP32_Slave_lbs";
const char* hc06Password = "1234";


static int currentIndex = 0;
static int row = 0;
uint8_t address[6]={0xC5,0xE1,0x7B,0xBE,0xFC,0x67};

// 定义结构体数组

uint8_t n=0;
const int buttonPin = 12;  // 使用GPIO4作为按钮输入引脚

const int MAX_ITEMS = 12;  // 数组最大元素数量
struct Item {
  const char* address;  // 存储地址
  uint8_t number;       // 存储数字
  uint8_t order;         // 存储行数
};

Item itemArray[MAX_ITEMS] = {
  {"A1", 0, 0},
  {"A2", 0, 1},
  {"A3", 0, 2},
  {"C3", 0, 8},
  {"C2", 0, 7},
  {"C1", 0, 6},
  {"B1", 0, 3},
  {"B2", 0, 4},
  {"B3", 0, 5},
  {"D3", 0, 11},
  {"D2", 0, 10},
  {"D1", 0, 9},
};

TFT_eSPI tft = TFT_eSPI();  // 初始化TFT对象

void drawTable() {
    tft.drawRect(5, 20, 230, 280, TFT_WHITE);  // 外边框
    tft.drawFastHLine(5, 50, 230, TFT_WHITE);  // 表头分隔线
    tft.drawFastVLine(55, 20, 280, TFT_WHITE);  // 列分隔线
    tft.setTextSize(2);
    tft.setCursor(15, 30);
    tft.print("Num");
    tft.setCursor(20, 60);
    tft.print("A1");
    tft.setCursor(20, 80);
    tft.print("A2");
    tft.setCursor(20, 100);
    tft.print("A3");
    tft.setCursor(20, 120);
    tft.print("B1");
    tft.setCursor(20, 140);
    tft.print("B2");
    tft.setCursor(20, 160);
    tft.print("B3");
    tft.setCursor(20, 180);
    tft.print("C1");
    tft.setCursor(20, 200);
    tft.print("C2");
    tft.setCursor(20, 220);
    tft.print("C3");

    tft.setCursor(20, 240);
    tft.print("D1");
    tft.setCursor(20, 260);
    tft.print("D2");
    tft.setCursor(20, 280);
    tft.print("D3");
    tft.setCursor(110, 30);
    tft.print("Mess");
  }
  

  void updateDisplay(const char* id, uint8_t mess) {
    //static int row = 0;
    //int yPos = 60 + row * 20;  // 每行高度20像素+初始高度
  
    // 清空当前行
    tft.fillRect(10, 80, 220, 18, TFT_BLACK);
  
    // 显示货物编号（居中）
    tft.setTextSize(3);
    tft.setCursor(20, 80);
    tft.print(id);
  
    // 显示位置坐标（居中）
    tft.setCursor(120, 80);
    tft.print(mess);
  
    //row = row + 1;  // 限制显示10行（超出后覆盖最旧数据）
  }
  

  void updateDisplay1(uint8_t number) {

    row = itemArray[currentIndex].order;
    int yPos = 60 + row * 20;  // 每行高度20像素+初始高度
    
    // 清空当前行
    tft.fillRect(10, yPos, 220, 18, TFT_BLACK);
  
    // // 显示货物编号（居中）
    tft.setTextSize(2);
    tft.setCursor(20, yPos);
    tft.print(itemArray[currentIndex].address);
    

    //测试currentindex增加

    // 显示位置坐标（居中）
    tft.setCursor(120, yPos);
    tft.print(number);
    tft.drawFastVLine(55, 20, 280, TFT_WHITE);  // 列分隔线
    
     // 
 
  }

  void tft_init(){
    tft.init();
    tft.setRotation(0);  // 屏幕旋转方向（根据实际调整）
    tft.fillScreen(TFT_BLACK);  // 清屏为黑色
    tft.setTextColor(TFT_WHITE, TFT_BLACK);  // 白字黑底 
  }

  void key_scan(){
    int buttonState = digitalRead(buttonPin);
  
    if (buttonState == LOW&&n==1) {
    
      //Serial.println("按钮被按下");
      n++;
      delay(200);  // 简单的防抖延迟

    }
  }

#endif