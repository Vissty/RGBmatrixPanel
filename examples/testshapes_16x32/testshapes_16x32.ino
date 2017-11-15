/*
该例程展示RGBmatrixPanel绘图功能
*/

#include <RGBmatrixPanel.h>
#include <math.h>

#define CLK D6
#define OE  D7
#define LAT A4
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup()
{
    matrix.begin();

    // 画一个白色的像素点
    matrix.drawPixel(0, 0, matrix.Color333(7, 7, 7));
    delay(500);

    // 用绿色填充屏幕
    matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 7, 0));
    delay(500);

    // 画一个黄色的盒子
    matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));
    delay(500);

    // 画一个红的的'X'
    matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 0, 0));
    matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 0, 0));
    delay(500);

    // 画一个蓝色的圆
    matrix.drawCircle(7, 7, 7, matrix.Color333(0, 0, 7));
    delay(500);

    // 画一个紫色的圆
    matrix.fillCircle(23, 7, 7, matrix.Color333(7, 0, 7));
    delay(500);

    // 用黑色填充屏幕
    matrix.fillScreen(matrix.Color333(0, 0, 0));

    // 显示一些文字
    matrix.setCursor(1, 0);
    matrix.setTextSize(1);

    // 用彩虹的颜色显示每个字母
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.print('1');
    matrix.setTextColor(matrix.Color333(7,4,0));
    matrix.print('6');
    matrix.setTextColor(matrix.Color333(7,7,0));
    matrix.print('x');
    matrix.setTextColor(matrix.Color333(4,7,0));
    matrix.print('3');
    matrix.setTextColor(matrix.Color333(0,7,0));
    matrix.print('2');

    matrix.setCursor(1, 9);  //下一行
    matrix.setTextColor(matrix.Color333(0,7,7));
    matrix.print('*');
    matrix.setTextColor(matrix.Color333(0,4,7));
    matrix.print('R');
    matrix.setTextColor(matrix.Color333(0,0,7));
    matrix.print('G');
    matrix.setTextColor(matrix.Color333(4,0,7));
    matrix.print("B");
    matrix.setTextColor(matrix.Color333(7,0,4));
    matrix.print("*");
}

void loop()
{

}
