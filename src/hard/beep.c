#include "BEEP.H"
void beep_init()
{
//	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // 使能IOCON时钟 
//	
//	LPC_IOCON->R_PIO0_1 &= ~0x07;    
//	LPC_IOCON->R_PIO0_1 |= 0x01; //把P1.0脚设置为GPIO

//	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // 禁能IOCON时钟

	LPC_GPIO0->DIR |= (1<<1); // 把P0.1设置为输出引脚
	LPC_GPIO0->DATA |= (1<<1); // 把P0.1设置为高电平

}

void BEEP_ON(void)    
{
	LPC_GPIO0->DATA &= ~(1<<1);
}

void BEEP_OFF(void)   
{
	LPC_GPIO0->DATA |= (1<<1);
}

