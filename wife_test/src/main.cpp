#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
// put function declarations here:

/*wifi*/
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  // 初始化 I2C 总线
  Wire.begin();
  // 初始化 OLED 显示屏
  u8g2.begin();
}

void loop() {
  // 清空缓冲区
  u8g2.firstPage();
  do {
    // 设置字体
    u8g2.setFont(u8g2_font_ncenB08_tr);
    // 在指定位置绘制文本
    u8g2.drawStr(0, 15, "Hello, World!");
  } while ( u8g2.nextPage() );

  delay(1000);
}