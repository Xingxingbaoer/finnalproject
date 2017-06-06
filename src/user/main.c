#include "LPC11xx.h"
#include "oled.h"
#include "ui.h"
#include "adc.h"
#include "key.h"
#include "uart.h"
#include "delay.h"
#include "i2c.h"
#include "24c02.h"
#include "temperature.h"

extern  float low_temp ;
extern 	float high_temp ;
extern 	int   lastlow_temp ;
extern 	int   lasthigh_temp ; 
	





extern int key_value;
int main()
{
	
	ADC_Init(7);
	UART_Init();										
	I2C_Init(1);			
	OLED_Init();
	key_init();
	
	
	
	
	low_temp= AT24C02_ReadOneByte(0x01);
	high_temp= AT24C02_ReadOneByte(0x02);
	while(1)
	{
	   
		UI();
	}
	


}
