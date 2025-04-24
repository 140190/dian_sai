#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include <Wire.h>
#include <U8g2lib.h>
#include <Arduino.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);


//char text[30];
void oled_init(void) 
{
    // 初始化 I2C 总线
    Wire.begin();
    // 初始化 OLED 显示屏
    u8g2.begin();
}
void oled_show_char(const char* str, int x, int yi)
{
    uint8_t y;
    y = yi*15;
    u8g2.firstPage();
    do {
        // 设置字体
        u8g2.setFont(u8g2_font_ncenB08_tr);
        // 在指定位置绘制文本
        u8g2.drawStr(x, y, str);//y 15为一行
    } while ( u8g2.nextPage() );
}
#endif