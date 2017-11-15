/*
该例证展示如何显示一个位图
*/

#include <RGBmatrixPanel.h>
#include "image.h"

#define CLK D6
#define OE  D7
#define LAT A4
#define A   A0
#define B   A1
#define C   A2
#define D	 A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup()
{
    int i, len;
    uint8_t *ptr = matrix.backBuffer();

    // 复制位图至矩阵缓存中
    memcpy(ptr, img, sizeof(img));

    // 开始显示
    matrix.begin();
}

void loop()
{

}
