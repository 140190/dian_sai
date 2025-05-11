


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
    SerialBT.setPin(hc06Password);

    bool connected =  SerialBT.connect(address);

 
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
          if(n==0)
          {
            String received = SerialBT.readStringUntil('\n');
            uint8_t value = received.toInt();
            if(currentIndex<12)
            {
            // 更新结构体数组中的数字
              itemArray[currentIndex].number = value;
      
              // 更新显示屏
              updateDisplay1(itemArray[currentIndex].number);
              
              // 更新索引，超出数组长度后置一，准备进入第二模式
              currentIndex = currentIndex + 1;

            
           
              if(currentIndex==12)
              {
                n=1;


              }
            }
     
          }
          else if(n==3)
          {
            tft.fillRect(0, 0, 500, 500, TFT_BLACK);
            String received = SerialBT.readStringUntil('\n');
            uint8_t value = received.toInt();
            for(int i=0;i<12;i++)
            {
              if(itemArray[i].number==value)
              {
                updateDisplay(itemArray[i].address, itemArray[i].number);

              }
            }
          }
        }
        if(n==2)
        {
          tft.fillRect(0, 0, 500, 500, TFT_BLACK);
          tft.setTextSize(2);
          tft.setCursor(100, 30);
          tft.print("Way2");

          tft.println("waiting for connect...");
          SerialBT.setPin(hc06Password);
    
          bool connected =  SerialBT.connect(address);
          if (!connected) {
            tft.fillRect(0, 0, 500, 500, TFT_BLACK);
            tft.setCursor(10, 50);
            tft.println("Connection failed");
            tft.setCursor(10, 80);
            tft.print("Retrying...");
            
            // 添加重试逻辑
            int retryCount = 0;
            while (!connected && retryCount < 5) { // 最多重试5次
              delay(2000); // 2秒后重试
              SerialBT.setPin(hc06Password);
    
              connected =  SerialBT.connect(address);
              retryCount++;
              
              // 更新重试提示
              tft.fillRect(10, 80, 200, 20, TFT_BLACK);
              tft.setCursor(10, 80);
              tft.print("Retry attempt ");
              tft.print(retryCount);
            }
          }
          if (connected) {
            tft.fillRect(0, 0, 500, 500, TFT_BLACK);
            tft.setCursor(130, 10);
            
            tft.setCursor(10, 10);
            tft.println("Connected!");
        
          }
            n++;
            tft.println(n);
        
  // }   tft.setTextSize(2);

       }
    tft.setTextSize(2);
    tft.setCursor(150, 0);
    tft.print(currentIndex);
    tft.setCursor(170, 0);
    tft.print("n");
    tft.setCursor(190, 0);
    tft.print(n);
          key_scan();
  }



