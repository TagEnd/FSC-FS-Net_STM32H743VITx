#include "lcd.h"
#include "spi.h"
#include "stdint.h"
#include "lvgl.h"

uint16_t ST7789_X_Start = ST7789_XSTART;
uint16_t ST7789_Y_Start = ST7789_YSTART;
uint16_t ST7789_Width = ST7789_WIDTH;
uint16_t ST7789_Height = ST7789_HEIGHT;

/**
 * @brief LCD传输指令
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void LCD_Write_Cmd(uint8_t data)
{
    LCD_CS_L;
    LCD_DC_L;
    HAL_SPI_Transmit(&hspi2, &data, 1, 0xff);
    LCD_CS_H;
    LCD_DC_H;
}

/**
 * @brief LCD传输数据
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void LCD_Write_Data(uint8_t data)
{
    LCD_CS_L;
    LCD_DC_H;
    HAL_SPI_Transmit(&hspi2, &data, 1, 0xff);
    LCD_CS_H;
    LCD_DC_L;
}

/**
 * @brief LCD复位
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void LCD_RST(void)
{
    LCD_RST_L;
    HAL_Delay(10);
    LCD_RST_H;
    HAL_Delay(120);
    LCD_CS_H;
}

/**
 * @brief LCD初始化(小白版本)
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
volatile void LCD_Init(void)
{
    LCD_BLK_H;
    LCD_RST();
    LCD_Write_Cmd(0x01); // Software Reset
    HAL_Delay(120);
    LCD_Write_Cmd(0x11); // Sleep Out
    HAL_Delay(120);
    //-----------------------ST7789V Frame rate setting-----------------//
    LCD_Write_Cmd(0x3A); // 65k mode
    LCD_Write_Data(0x05);
    LCD_Write_Cmd(0xC5); // VCOM
    LCD_Write_Data(0x1A);
    LCD_Write_Cmd(0x36); // 屏幕显示方向设置
    LCD_Write_Data(0x00);
    LCD_Write_Cmd(0xb2); // Porch Setting
    LCD_Write_Data(0x05);
    LCD_Write_Data(0x05);
    LCD_Write_Data(0x00);
    LCD_Write_Data(0x33);
    LCD_Write_Data(0x33);
    LCD_Write_Cmd(0xb7);  // Gate Control
    LCD_Write_Data(0x05); // 12.2v   -10.43v
    //--------------ST7789V Power setting---------------//
    LCD_Write_Cmd(0xBB); // VCOM
    LCD_Write_Data(0x3F);
    LCD_Write_Cmd(0xC0); // Power control
    LCD_Write_Data(0x2c);
    LCD_Write_Cmd(0xC2); // VDV and VRH Command Enable
    LCD_Write_Data(0x01);
    LCD_Write_Cmd(0xC3);  // VRH Set
    LCD_Write_Data(0x0F); // 4.3+( vcom+vcom offset+vdv)
    LCD_Write_Cmd(0xC4);  // VDV Set
    LCD_Write_Data(0x20); // 0v
    LCD_Write_Cmd(0xC6);  // Frame Rate Control in Normal Mode
    LCD_Write_Data(0x01); // 111Hz
    LCD_Write_Cmd(0xd0);  // Power Control 1
    LCD_Write_Data(0xa4);
    LCD_Write_Data(0xa1);
    LCD_Write_Cmd(0xE8); // Power Control 1
    LCD_Write_Data(0x03);
    LCD_Write_Cmd(0xE9); // Equalize time control
    LCD_Write_Data(0x09);
    LCD_Write_Data(0x09);
    LCD_Write_Data(0x08);
    //---------------ST7789V gamma setting-------------//
    LCD_Write_Cmd(0xE0); // Set Gamma
    LCD_Write_Data(0xD0);
    LCD_Write_Data(0x05);
    LCD_Write_Data(0x09);
    LCD_Write_Data(0x09);
    LCD_Write_Data(0x08);
    LCD_Write_Data(0x14);
    LCD_Write_Data(0x28);
    LCD_Write_Data(0x33);
    LCD_Write_Data(0x3F);
    LCD_Write_Data(0x07);
    LCD_Write_Data(0x13);
    LCD_Write_Data(0x14);
    LCD_Write_Data(0x28);
    LCD_Write_Data(0x30);
    LCD_Write_Cmd(0xE1); // Set Gamma
    LCD_Write_Data(0xD0);
    LCD_Write_Data(0x05);
    LCD_Write_Data(0x09);
    LCD_Write_Data(0x09);
    LCD_Write_Data(0x08);
    LCD_Write_Data(0x03);
    LCD_Write_Data(0x24);
    LCD_Write_Data(0x32);
    LCD_Write_Data(0x32);
    LCD_Write_Data(0x3B);
    LCD_Write_Data(0x14);
    LCD_Write_Data(0x13);
    LCD_Write_Data(0x28);
    LCD_Write_Data(0x2F);
    LCD_Write_Cmd(0x20); // 反显
    HAL_Delay(120);
    LCD_Write_Cmd(0x29); // 开启显示
}

/**
 * @brief LCD进入休眠
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void LCD_enter_sleep(void)
{
    LCD_Write_Cmd(ST7789_SLPIN);
}

/**
 * @brief 退出休眠
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void LCD_exit_sleep(void)
{
    LCD_Write_Cmd(ST7789_SLPOUT);
}

/**
 * @brief 设置列
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
static void ST7789_ColumnSet(uint16_t ColumnStart, uint16_t ColumnEnd)
{
    if (ColumnStart > ColumnEnd)
    {
        return;
    }
    if (ColumnEnd > ST7789_Width)
    {
        return;
    }
    ColumnStart += ST7789_X_Start;
    ColumnEnd += ST7789_X_Start;
    LCD_Write_Cmd(ST7789_CASET);
    LCD_Write_Data((ColumnStart >> 8) & 0xff);
    LCD_Write_Data(ColumnStart & 0xff);
    LCD_Write_Data((ColumnEnd >> 8) & 0xff);
    LCD_Write_Data(ColumnEnd & 0xff);
}

/**
 * @brief 设置行
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
static void ST7789_RowSet(uint16_t RowStart, uint16_t RowEnd)
{
    if (RowStart > RowEnd)
    {
        return;
    }
    if (RowEnd > ST7789_Height)
    {
        return;
    }
    RowStart += ST7789_Y_Start;
    RowEnd += ST7789_Y_Start;
    LCD_Write_Cmd(ST7789_RASET);
    LCD_Write_Data((RowStart >> 8) & 0xff);
    LCD_Write_Data(RowStart & 0xff);
    LCD_Write_Data((RowEnd >> 8) & 0xff);
    LCD_Write_Data(RowEnd & 0xff);
}

/**
 * @brief 设置坐标
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    ST7789_ColumnSet(x0, x1);
    ST7789_RowSet(y0, y1);
    LCD_Write_Cmd(ST7789_RAMWR);
}

/**
 * @brief 向LCD写入多个u16
 * @describe
 * @author Cai cai
 * @param len 写入个数
 * @return
 */
void ST7789_RamWrite(uint16_t *pbuf, uint32_t len)
{
    static uint8_t buf[2];
    LCD_CS_L;
    LCD_DC_H;
    buf[0] = *pbuf >> 8;
    buf[1] = *pbuf & 0xff;
    while (len--)
    {
        {
            HAL_SPI_Transmit(&hspi2, (uint8_t *)buf, 2, 0xff);
        }
    }
    LCD_DC_L;
    LCD_CS_H;
}

/**
 * @brief 填充区域
 * @describe
 * @author Cai cai
 * @param x,y 起始坐标，w,h填充的宽和高，color填充颜色
 * @return
 */
void ST7789_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
    if ((x >= ST7789_Width) || (y >= ST7789_Height))
    {
        return;
    }
    if ((x + w) > ST7789_Width)
    {
        w = ST7789_Width - x;
    }
    if ((y + h) > ST7789_Height)
    {
        h = ST7789_Height - y;
    }
    ST7789_SetWindow(x, y, x + w - 1, y + h - 1);
    ST7789_RamWrite(&color, (h * w));
}

/**
 * @brief 填充整个屏幕
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_FillScreen(uint16_t color)
{
    ST7789_FillRect(0, 0, ST7789_Width, ST7789_Height, color);
}

#if LVGL_EN == 0
/**
 * @brief 绘制一个点
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
    if ((x < 0) || (x >= ST7789_Width) || (y < 0) || (y >= ST7789_Height))
    {
        return;
    }
    ST7789_SetWindow(x, y, x, y);
    ST7789_RamWrite(&color, 1);
}

/**
 * @brief 绘制直线，一个一个点绘制
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
static void ST7789_DrawLine_Slow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
    const int16_t deltaX = abs(x2 - x1);
    const int16_t deltaY = abs(y2 - y1);
    const int16_t signX = x1 < x2 ? 1 : -1;
    const int16_t signY = y1 < y2 ? 1 : -1;
    int16_t error = deltaX - deltaY;
    ST7789_DrawPixel(x2, y2, color);
    while (x1 != x2 || y1 != y2)
    {
        ST7789_DrawPixel(x1, y1, color);
        const int16_t error2 = error * 2;
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }
}

/**
 * @brief 绘制直线,通过绘制矩形的方式绘制直线
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
    if (x1 == x2)
    {
        if (y1 > y2)
        {
            ST7789_FillRect(x1, y2, 1, y1 - y2 + 1, color);
        }
        else
        {
            ST7789_FillRect(x1, y1, 1, y2 - y1 + 1, color);
        }
        return;
    }
    if (y1 == y2)
    {
        if (x1 > x2)
        {
            ST7789_FillRect(x2, y1, x1 - x2 + 1, 1, color);
        }
        else
        {
            ST7789_FillRect(x1, y1, x2 - x1 + 1, 1, color);
        }
        return;
    }
    ST7789_DrawLine_Slow(x1, y1, x2, y2, color);
}

/**
 * @brief 绘制矩形，不填充
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
    ST7789_DrawLine(x1, y1, x1, y2, color);
    ST7789_DrawLine(x2, y1, x2, y2, color);
    ST7789_DrawLine(x1, y1, x2, y1, color);
    ST7789_DrawLine(x1, y2, x2, y2, color);
}

/**
 * @brief 清除整个屏幕
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_Clear(void)
{
    ST7789_FillRect(0, 0, ST7789_Width, ST7789_Height, ST7789_WHITE);
}

/**
 * @brief 交换两个u16的值
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
static void SwapInt16Values(int16_t *pValue1, int16_t *pValue2)
{
    int16_t TempValue = *pValue1;
    *pValue1 = *pValue2;
    *pValue2 = TempValue;
}

/**
 * @brief 绘制矩形，填充
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_DrawRectangleFilled(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t fillcolor)
{
    if (x1 > x2)
    {
        SwapInt16Values(&x1, &x2);
    }
    if (y1 > y2)
    {
        SwapInt16Values(&y1, &y2);
    }
    ST7789_FillRect(x1, y1, x2 - x1, y2 - y1, fillcolor);
}

/**
 * @brief 填充圆形
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_DrawCircleFilled(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t fillcolor)
{
    int x = 0;
    int y = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while (y >= 0)
    {
        ST7789_DrawLine(x0 + x, y0 - y, x0 + x, y0 + y, fillcolor);
        ST7789_DrawLine(x0 - x, y0 - y, x0 - x, y0 + y, fillcolor);
        error = 2 * (delta + y) - 1;
        if (delta < 0 && error <= 0)
        {

            ++x;
            delta += 2 * x + 1;
            continue;
        }
        error = 2 * (delta - x) - 1;
        if (delta > 0 && error > 0)
        {
            --y;
            delta += 1 - 2 * y;
            continue;
        }
        ++x;
        delta += 2 * (x - y);
        --y;
    }
}

/**
 * @brief 绘制圆形
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_DrawCircle(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color)
{
    int x = 0;
    int y = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while (y >= 0)
    {
        ST7789_DrawPixel(x0 + x, y0 + y, color);
        ST7789_DrawPixel(x0 + x, y0 - y, color);
        ST7789_DrawPixel(x0 - x, y0 + y, color);
        ST7789_DrawPixel(x0 - x, y0 - y, color);
        error = 2 * (delta + y) - 1;
        if (delta < 0 && error <= 0)
        {
            ++x;
            delta += 2 * x + 1;
            continue;
        }
        error = 2 * (delta - x) - 1;
        if (delta > 0 && error > 0)
        {
            --y;
            delta += 1 - 2 * y;
            continue;
        }
        ++x;
        delta += 2 * (x - y);
        --y;
    }
}

/**
 * @brief 显示一个英文字符
 * @describe
 * @author Cai cai
 * @param TextColor 文本颜色
 * @param BgColor 背景颜色
 * @param TransparentBg 是否显示背景 1：显示 0：不显示
 * @param Font 字体模型
 * @param multiplier 字体大小设置
 * @param ch 显示的字符
 * @return
 */
void ST7789_DrawChar(
    uint16_t x, uint16_t y,
    uint16_t TextColor, uint16_t BgColor,
    uint8_t TransparentBg,
    FontDef_t *Font, uint8_t multiplier, unsigned char ch)
{
    uint32_t i, b, j;
    uint32_t X = x, Y = y;
    uint8_t xx, yy;
    if (multiplier < 1)
    {
        multiplier = 1;
    }
    if (ST7789_Width >= (x + Font->FontWidth) || ST7789_Height >= (y + Font->FontHeight))
    {
        for (i = 0; i < Font->FontHeight; i++)
        {
            if (ch < 127)
            {
                b = Font->data[(ch - 32) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch > 191)
            {
                b = Font->data[((ch - 192) + 96) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 168)
            {
                b = Font->data[(160) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 184)
            {
                b = Font->data[(161) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 170)
            {
                b = Font->data[(162) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 175)
            {
                b = Font->data[(163) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 178)
            {
                b = Font->data[(164) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 179)
            {
                b = Font->data[(165) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 186)
            {
                b = Font->data[(166) * Font->FontHeight + i];
            }
            else if ((uint8_t)ch == 191)
            {
                b = Font->data[(167) * Font->FontHeight + i];
            }
            for (j = 0; j < Font->FontWidth; j++)
            {
                if ((b << j) & 0x8000)
                {
                    for (yy = 0; yy < multiplier; yy++)
                    {
                        for (xx = 0; xx < multiplier; xx++)
                        {
                            ST7789_DrawPixel(X + xx, Y + yy, TextColor);
                        }
                    }
                }
                else if (TransparentBg)
                {
                    for (yy = 0; yy < multiplier; yy++)
                    {
                        for (xx = 0; xx < multiplier; xx++)
                        {
                            ST7789_DrawPixel(X + xx, Y + yy, BgColor);
                        }
                    }
                }
                X = X + multiplier;
            }
            X = x;
            Y = Y + multiplier;
        }
    }
}

/**
 * @brief 显示一串英文字符
 * @describe
 * @author Cai cai
 * @param
 * @return
 */
void ST7789_print(uint16_t x, uint16_t y, uint16_t TextColor, uint16_t BgColor, uint8_t TransparentBg, FontDef_t *Font, uint8_t multiplier, char *str)
{
    if (multiplier < 1)
    {
        multiplier = 1;
    }
    unsigned char buff_char;
    uint16_t len = strlen(str);
    while (len--)
    {
        if ((uint8_t)*str >= 0xC0)
        {
            switch ((uint8_t)*str)
            {
            case 0xD0:
            {
                str++;
                if ((uint8_t)*str >= 0x90 && (uint8_t)*str <= 0xBF)
                {
                    buff_char = (*str) + 0x30;
                }
                else if ((uint8_t)*str == 0x81)
                {
                    buff_char = 0xA8;
                    break;
                }
                else if ((uint8_t)*str == 0x84)
                {
                    buff_char = 0xAA;
                    break;
                }
                else if ((uint8_t)*str == 0x86)
                {
                    buff_char = 0xB2;
                    break;
                }
                else if ((uint8_t)*str == 0x87)
                {
                    buff_char = 0xAF;
                    break;
                }
                break;
            }
            case 0xD1:
            {
                str++;
                if ((uint8_t)*str >= 0x80 && (uint8_t)*str <= 0x8F)
                {
                    buff_char = (*str) + 0x70;
                }
                else if ((uint8_t)*str == 0x91)
                {
                    buff_char = 0xB8;
                    break;
                }
                else if ((uint8_t)*str == 0x94)
                {
                    buff_char = 0xBA;
                    break;
                }
                else if ((uint8_t)*str == 0x96)
                {
                    buff_char = 0xB3;
                    break;
                }
                else if ((uint8_t)*str == 0x97)
                {
                    buff_char = 0xBF;
                    break;
                }
                break;
            }
            }
            len--;
            ST7789_DrawChar(x, y, TextColor, BgColor, TransparentBg, Font, multiplier, buff_char);
        }
        else
        {
            ST7789_DrawChar(x, y, TextColor, BgColor, TransparentBg, Font, multiplier, *str);
        }
        x = x + (Font->FontWidth * multiplier);
        str++;
    }
}
#endif

#if LVGL_EN
uint16_t dataSwap[TFT_COLUMN_NUMBER] = {0};

uint16_t swap_uint16(uint16_t data)
{
    return (data << 8) | (data >> 8);
}

void lvgl_LCD_Write_Buf(lv_color_t *color, uint16_t len)
{
    static uint8_t is_init = 0;
    if (is_init == 0)
    {
        is_init = 1;
        memset(dataSwap, 0, TFT_COLUMN_NUMBER);
    }
    uint16_t i;
    for (i = 0; i < len; i++)
    {
        dataSwap[i] = ~swap_uint16(*(uint16_t *)color++);
    }
    HAL_SPI_Transmit(&hspi2, (uint8_t *)dataSwap, len * 2, 100);
}
void LCD_Fill_LVGL(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, lv_color_t *color)
{
    uint16_t i;
    static uint16_t tmp;
    tmp = xend - xsta + 1;
    ST7789_SetWindow(xsta, ysta, xend, yend); // 设置显示范围
    LCD_DC_H;
    LCD_CS_L;
    for (i = ysta; i <= yend; i++)
    {
        lvgl_LCD_Write_Buf(color, tmp);
        // HAL_SPI_Transmit(&hspi1, (uint8_t *)color, tmp * 2, 100);
        color += (tmp);
    }
    LCD_CS_H;
}
#endif