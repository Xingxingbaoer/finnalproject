#ifndef _OELD_H
#define _OELD_H
#include "LPC11xx.H"
extern void OLED_Init(void);
extern void OLED_WrCmd(uint8_t  cmd);
extern void Dly_ms(uint16_t ms);
extern void OLED_WrDat(uint8_t data);
extern void OLED_Set_Pos(uint8_t x, uint8_t y);
extern void OLED_Fill(uint8_t bmp_data);
extern void OLED_CLS(void);
extern void OLED_DLY_ms(uint16_t ms);
extern void GpioInit(void);
extern void OLED_PutPixel(uint8_t x,uint8_t y,uint8_t data1);
extern void OLED_Rectangle(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t gif);
extern void OLED_P8x16Str(uint8_t x,uint8_t y,uint8_t ch[]);
extern void OLED_P6x8Str(uint8_t x,uint8_t y,uint8_t ch[]);
extern void OLED_P14x16Str(uint8_t x,uint8_t y,uint8_t ch[]);
extern void OLED_Print(uint8_t x, uint8_t y, uint8_t ch[]);
extern void OLED_PrintNum(uint8_t x,uint8_t y,uint8_t n);
#endif
