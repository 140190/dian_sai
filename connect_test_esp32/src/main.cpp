#include <HardwareSerial.h>
#include <Arduino.h>
// 定义UART1对象


// 自定义引脚，可根据实际情况修改
const int txPin = 17;
const int rxPin = 16;
uint8_t state;
void setup() {
  // 初始化UART1，波特率115200
  Serial1.begin(115200, SERIAL_8N1, rxPin, txPin);
  Serial.begin(115200);
  while (!Serial1);
}

void loop() {
  // 发送数据
  /*条件发送数据，请求停车*/
//  if()
//  {
  if(state == 1)
  {
    Serial1.write(0x01); // 发送数据0x01
  }

  if (Serial.available()) 
  {
    if(Serial.read()==0x01)
    {
      Serial.println("0k");
      state++;
    }
    else
    {
      Serial.println("error");
    }
    
  }
  if (Serial1.available()) {
    if(Serial1.read()==0x01)
    {
      Serial.println("回传ok"); 
      state = 0;
    }
  }
//  }
  //delay(1000); 
  // 延时1秒
  //delay(1000);
}