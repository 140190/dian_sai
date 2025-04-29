#include <SPI.h>


#include <TFT_eSPI.h>
//#include <FreeFonts.h> // 引入 FreeFonts 头文件

TFT_eSPI tft = TFT_eSPI();  // 初始化TFT对象
// 绘制表格框架
void drawTable() {
  tft.drawRect(5, 40, 230, 200, TFT_WHITE);  // 外边框
  tft.drawFastHLine(5, 70, 230, TFT_WHITE);  // 表头分隔线
  tft.setTextSize(1);
  tft.setCursor(20, 50);
  tft.print("货物编号");
  tft.setCursor(120, 50);
  tft.print("位置坐标");
}

// 更新显示内容（单行）
void updateDisplay(int id, const char* location) {
  static int row = 0;
  int yPos = 80 + row * 20;  // 每行高度20像素

  // 清空当前行
  tft.fillRect(10, yPos, 220, 18, TFT_BLACK);

  // 显示货物编号（居中）
  tft.setTextSize(2);
  tft.setCursor(20, yPos);
  tft.print(id);

  // 显示位置坐标（居中）
  tft.setCursor(120, yPos);
  tft.print(location);

  row = (row + 1) % 10;  // 限制显示10行（超出后覆盖最旧数据）
}
// 货物坐标定义（A1~D3）
const char* locations[12] = {
  "A1", "A2", "A3", 
  "B1", "B2", "B3", 
  "C1", "C2", "C3", 
  "D1", "D2", "D3"
};

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(3);  // 屏幕旋转方向（根据实际调整）
  tft.fillScreen(TFT_BLACK);  // 清屏为黑色
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  // 白字黑底
  // 设置字体
  //tft.setFreeFont(&FreeSans9pt7b); // 使用 FreeSans9pt7b 字体
  // 显示标题
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("盘点结果实时显示");

  // 初始化显示表格
  drawTable();
}

void loop() {
  // 模拟盘点数据更新（实际替换为您的数据输入逻辑）
  static int itemID = 1;
  static int locationIndex = 0;

  if (itemID <= 12) {
    updateDisplay(itemID, locations[locationIndex]);
    itemID++;
    locationIndex = (locationIndex + 1) % 12;
    delay(1000);  // 模拟1秒更新一次
  }
}

