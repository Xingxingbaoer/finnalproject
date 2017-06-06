#include "LPC11xx.h"
#include "ui.h"
#include "oled.h"
#include "delay.h"
#include "24c02.h"
#include "show.h"
#include "adc.h"

void SysTickInit(void)
{
	SysTick->CTRL&=~(1<<2);
	SysTick->LOAD=2499999;	//100ms
//	SysTick->LOAD=4999999;	//200ms
	SysTick->VAL=0;
	SysTick->CTRL|=((1<<1)|(1<<0));
	NVIC_EnableIRQ(SysTick_IRQn);
}	

