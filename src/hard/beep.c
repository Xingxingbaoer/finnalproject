#include "BEEP.H"
void beep_init()
{
//	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // ʹ��IOCONʱ�� 
//	
//	LPC_IOCON->R_PIO0_1 &= ~0x07;    
//	LPC_IOCON->R_PIO0_1 |= 0x01; //��P1.0������ΪGPIO

//	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // ����IOCONʱ��

	LPC_GPIO0->DIR |= (1<<1); // ��P0.1����Ϊ�������
	LPC_GPIO0->DATA |= (1<<1); // ��P0.1����Ϊ�ߵ�ƽ

}

void BEEP_ON(void)    
{
	LPC_GPIO0->DATA &= ~(1<<1);
}

void BEEP_OFF(void)   
{
	LPC_GPIO0->DATA |= (1<<1);
}

