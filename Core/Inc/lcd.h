#ifndef __LCD_H
#define __LCD_H

#include "main.h"
#include "font.h"
#include "lvgl.h"

#define LCD_CS_H HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
#define LCD_CS_L HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);

#define LCD_RST_H HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
#define LCD_RST_L HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);

#define LCD_DC_H HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);
#define LCD_DC_L HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);

#define LCD_BLK_H HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_SET);
#define LCD_BLK_L HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_RESET);

#define RGB565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

#define ST7789_BLACK ~0x0000
#define ST7789_BLUE ~0x001F
#define ST7789_RED ~0xF800
#define ST7789_GREEN ~0x07E0
#define ST7789_CYAN ~0x07FF
#define ST7789_MAGENTA ~0xF81F
#define ST7789_YELLOW ~0xFFE0
#define ST7789_WHITE ~0xFFFF

#define ST7789_SWRESET 0x01
#define ST7789_SLPIN 0x10
#define ST7789_SLPOUT 0x11
#define ST7789_NORON 0x13
#define ST7789_INVOFF 0x20
#define ST7789_INVON 0x21
#define ST7789_DISPOFF 0x28
#define ST7789_DISPON 0x29
#define ST7789_CASET 0x2A
#define ST7789_RASET 0x2B
#define ST7789_RAMWR 0x2C
#define ST7789_COLMOD 0x3A
#define ST7789_MADCTL 0x36

#define ST7789_ColorMode_65K 0x50
#define ST7789_ColorMode_262K 0x60
#define ST7789_ColorMode_12bit 0x03
#define ST7789_ColorMode_16bit 0x05
#define ST7789_ColorMode_18bit 0x06
#define ST7789_ColorMode_16M 0x07
//------------------------------------------------

#define ST7789_MADCTL_MY 0x80
#define ST7789_MADCTL_MX 0x40
#define ST7789_MADCTL_MV 0x20
#define ST7789_MADCTL_ML 0x10
#define ST7789_MADCTL_RGB 0x00
#define ST7789_MADCTL_BGR 0x08
#define ST7789_MADCTL_MH 0x04

#define ST7789_WIDTH 240
#define ST7789_HEIGHT 320
#define ST7789_XSTART 0
#define ST7789_YSTART 0
#define LVGL_EN 1
#define TFT_COLUMN_NUMBER 240

volatile void LCD_Init(void);
#if LVGL_EN == 0
void ST7789_DrawChar(uint16_t x, uint16_t y, uint16_t TextColor, uint16_t BgColor, uint8_t TransparentBg, FontDef_t *Font, uint8_t multiplier, unsigned char ch);
void ST7789_print(uint16_t x, uint16_t y, uint16_t TextColor, uint16_t BgColor, uint8_t TransparentBg, FontDef_t *Font, uint8_t multiplier, char *str);
void ST7789_DrawCircle(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color);
void ST7789_DrawCircleFilled(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t fillcolor);
void ST7789_DrawRectangleFilled(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t fillcolor);
void ST7789_Clear(void);
void ST7789_FillScreen(uint16_t color);
void ST7789_SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void ST7789_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void ST7789_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void ST7789_DrawLine_Slow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
#endif
void LCD_Fill_LVGL(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, lv_color_t *color);

#endif /*__LCD_H*/