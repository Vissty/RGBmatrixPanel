/*
该例程展示双缓冲显示
*/

#include <RGBmatrixPanel.h>
#include <math.h>


#define CLK D6
#define OE  D7
#define LAT A4
#define A   A0
#define B   A1
#define C   A2

#define pgm_read_word(addr) (*(const unsigned short *)(addr))

// 最后一个参数"true" 表示允许双缓存.
// 直到用户调用swapBuffers(),显示才会起效果
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);

const char str[] PROGMEM = "Adafruit 16x32 RGB LED Matrix";
int    textX   = matrix.width(),
       textMin = sizeof(str) * -12,
       hue     = 0;
int8_t ball[3][4] =
{
    {  3,  0,  1,  1 },
    { 17, 15,  1, -1 },
    { 27,  4, -1,  1 }
};
static const uint16_t PROGMEM ballcolor[3] =
{
    0x0080,
    0x0002,
    0x1000
};

void setup()
{
    matrix.begin();
    matrix.setTextWrap(false);
    matrix.setTextSize(2);
}

void loop()
{
    byte i;

    // 清屏
    matrix.fillScreen(0);

    for(i=0; i<3; i++)
    {
        // 画球
        matrix.fillCircle(ball[i][0], ball[i][1], 5, pgm_read_word(&ballcolor[i]));
        // 移动X,Y位置
        ball[i][0] += ball[i][2];
        ball[i][1] += ball[i][3];
        // 碰到边缘反弹
        if((ball[i][0] == 0) || (ball[i][0] == (matrix.width() - 1)))
        ball[i][2] *= -1;
        if((ball[i][1] == 0) || (ball[i][1] == (matrix.height() - 1)))
        ball[i][3] *= -1;
    }

    // 顶部写一段标语
    matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, true));
    matrix.setCursor(textX, 1);
    matrix.print(F(str));

    // 移动文字到左侧 , 变化颜色
    if((--textX) < textMin) textX = matrix.width();
    hue += 7;
    if(hue >= 1536) hue -= 1536;

    // 显示
    matrix.swapBuffers(false);
}
