#ifndef __NXP_ADC_H
#define __NXP_ADC_H

#include "LPC11xx.h"
#define  Vref   3300
extern uint32_t adc_value,R_ntc;
extern void ADC_Init(uint8_t Channel);	   // 初始化ADC口
extern uint32_t ADC_Read(uint8_t Channel);   // 读取电压值

#endif



