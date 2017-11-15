/*
该实例展示如何在RGB矩阵屏画一个彩环
*/

#include <RGBmatrixPanel.h>

#include <math.h>

#define PI					3.14159265358979f

#define CLK D6
#define OE  D7
#define LAT A4
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup()
{
    int      x, y, hue;
    float    dx, dy, d;
    uint8_t  sat, val;
    uint16_t c;

    matrix.begin();
    for(y=0; y < matrix.width(); y++)
    {
        dy = 15.5 - (float)y;
        for(x=0; x < matrix.height(); x++)
        {
            dx = 15.5 - (float)x;
            d  = dx * dx + dy * dy;
            if(d <= (16.5 * 16.5))
            {
                hue = (int)((atan2(-dy, dx) + PI) * 1536.0 / (PI * 2.0));
                d = sqrt(d);
                if(d > 15.5)
                {
                    // 消锯齿操作
                    sat = 255;
                    val = (int)((1.0 - (d - 15.5)) * 255.0 + 0.5);
                }
                else
                {
                    // 中间为白色
                    sat = (int)(d / 15.5 * 255.0 + 0.5);
                    val = 255;
                }
                c = matrix.ColorHSV(hue, sat, val, true);
            }
            else
            {
                c = 0;
            }
            matrix.drawPixel(x, y, c);
        }
    }
}

void loop()
{

}
