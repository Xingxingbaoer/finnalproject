#include "pwm.h"
#include "LPC11XX.H"
void pwm_init(uint32_t interval, uint16_t cycle)
{
	if(cycle<1||cycle>99)return ;
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);
	LPC_IOCON->R_PIO1_2 &= ~(0x07);
	LPC_IOCON->R_PIO1_2 |=0x03;
	LPC_SYSCON->SYSAHBCLKCTRL &=~(1<<16);
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<10);
	LPC_TMR32B1->TCR=0x02;
	LPC_TMR32B1->PR=0;
	LPC_TMR32B1->MCR=0x02<<9;
	LPC_TMR32B1->PWMC=0x02;
//	LPC_TMR32B1->MR1=interval*cycle/100;
	LPC_TMR32B1->MR1=interval-interval*cycle/100;
	LPC_TMR32B1->MR3=interval;
	LPC_TMR32B1->TCR=0x01;
}

