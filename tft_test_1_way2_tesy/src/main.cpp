


//#include <FreeFonts.h> // 引入 FreeFonts 头文件
#include<tft.hpp>

//定义名称及密码







void setup() {
  //Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // 启用内部上拉电阻
  tft_init();
  // 设置字体
  //tft.setFreeFont(&FreeSans9pt7b); // 使用 FreeSans9pt7b 字体
  // 显示标题
  SerialBT.begin("ESP32_Master_lbs",true); // 设置蓝牙设备名称
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("waiting for connect...");
  //SerialBT.setPin("1234");
 
    // 设置配对密码
    //SerialBT.setPin(hc06Password);

    bool connected =  SerialBT.connect(Blue_Name);

 
  if (connected) {
    tft.fillRect(0, 0, 500, 500, TFT_BLACK);
    tft.setCursor(10, 10);
    
    tft.println("Connected!");

  }
  // 初始化显示表格
  tft.fillRect(0, 0, 500, 500, TFT_BLACK);
  drawTable();
}

void loop() {
  // 模拟盘点数据更新（实际替换为您的数据输入逻辑）
  // static uint8_t mess = 1;// 货物信息
  // static uint8_t IDIndex = 0;

  // if (IDIndex < 12) {
  //   updateDisplay(ID[IDIndex],mess);
  //   mess++;
  //   IDIndex = IDIndex + 1;
  //   tft.drawFastVLine(55, 20, 280, TFT_WHITE);  // 列分隔线
  //   delay(1000);  // 模拟1秒更新一次

        if (SerialBT.available()) 
        {

          
            tft.fillRect(0, 0, 500, 500, TFT_BLACK);
            String received = SerialBT.readStringUntil('\n');
            uint8_t value = received.toInt();
            tft.setTextSize(3);
            tft.setCursor(20, 30);
            tft.print(value);
            for(int i=0;i<12;i++)
            {
              //delay(2000);
              if(itemArray[i].number==value)
              {

                updateDisplay(itemArray[i].address, itemArray[i].number);
                break;
              }
            }
          
        }
       
  }



