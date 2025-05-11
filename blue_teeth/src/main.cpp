#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Slave_lbs");  // 从机模式
}

void loop() {
  // 示例：定时发送模拟数据
  if (Serial.available()) {
    // 读取串口数据
    String data = Serial.readStringUntil('\n');
    // 通过蓝牙发送数据
    SerialBT.println(data);
      
    Serial.print("launch! =");
    Serial.println(data);
  }
}
