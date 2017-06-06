#include "LPC11xx.h"
#include "stdio.h"
#include "string.h"
#include "adc.h"
#include "oled.h"
#include "uart.h"
#include "24c02.h"
#include "delay.h"
#include "KEY.H"
#include "temperature.h"
char GcRcvBuf[20];

  float low_temp = 0;
	float high_temp = 0;
	int   lastlow_temp = 0;
	int   lasthigh_temp = 0; 
	uint32_t   k,t;

	extern int key_value;


uint8_t temp(void)
{
	uint32_t i;
	
	
	uint32_t  res_value;
	uint32_t ulADCData;
	uint32_t ulADCbuf;
	UART_Init();
	ADC_Init(7);
	
	
		ulADCData = 0;
		for(i=0;i<10;i++)
		{
			LPC_ADC ->CR |=(1<<24);
			while((LPC_ADC ->DR [7] & 0x80000000) == 0);
			LPC_ADC ->CR |=(1<<24);
			while((LPC_ADC ->DR [7] & 0x80000000) == 0);
			ulADCbuf = LPC_ADC ->DR [7];
			ulADCbuf = (ulADCbuf >>6) & 0x3ff;
			ulADCData += ulADCbuf ;
		}
	
	ulADCData = ulADCData /10;
	ulADCData = (ulADCData * 3300)/1024;
	res_value = ((ulADCData * 10000)/(3300-ulADCData));
		
		
		
		
		if((res_value < 33970)&&(res_value > 20310))//0~10
	{
		k=136600;
		t=(33970-res_value )*1000/k;
	}
	else if((res_value < 20311)&&(res_value > 12570))//10~20
	{
		k=77400;
		t=((20310-res_value)*1000/k)+100;
	}
	else if((res_value<12571)&&(res_value>8034))//20~30
	{
		k=45370;
		t=((12570-res_value)*1000/k)+200;
	}
	else if((res_value<8035)&&(res_value>5298))//30~40
	{
		k=27370;
		t=((8034-res_value)*1000/k)+300;
	}
	else if((res_value<5299)&&(res_value>3586))//40~50
	{
		k=17130;
		t=((5295-res_value)*1000/k)+400;
	}
	else if((res_value<3587)&&(res_value>2484))//50~60
	{
		k=11030;
		t=((3586-res_value)*1000/k)+500;
	}
	else if((res_value<2485)&&(res_value>1756))//60~70
	{
		k=7280;
		t=((2484-res_value)*1000/k)+600;
	}
	else if((res_value<1757)&&(res_value>1265))//70~80
	{
		k=4920;
		t=((1756-res_value)*1000/k)+700;
	}
	else if((res_value<1266)&&(res_value>926.6))//80~90
	{
		k=3394;
		t=((1266-res_value)*1000/k)+800;
	}
	else if((res_value<927.6)&&(res_value>690))//90~100
	{
		k=2366;
		t=((926.6-res_value)*1000/k)+900;
	}
	sprintf (GcRcvBuf , "temp= %4f\r\n",t);
	UART_SendStr(GcRcvBuf );
	


	return t;
}

void lowtemp_setting(void)
{
	if(lastlow_temp <=(-30))lastlow_temp = -30;
	
	low_temp = AT24C02_ReadOneByte(0x01);
	OLED_Print(5,0,"lowtemp_setting:");
	OLED_Print(5,2,"now :");
	OLED_PrintNum(50,2,lastlow_temp%100/10);
	OLED_PrintNum(60,2,lastlow_temp%10);
	
	if(key_value==6)
	{
		lastlow_temp ++;
		key_value =0;	
	}
	if(key_value ==7)
	{
		lastlow_temp --;
		key_value =0;
	}
	
	
	
}
void hightemp_setting(void)
{
	
	if(lasthigh_temp >=100)lasthigh_temp = 100;
	low_temp = AT24C02_ReadOneByte(0x02);
	OLED_Print(5,0,"hightemp_setting:");
	OLED_Print(5,2,"now :");
	OLED_PrintNum(50,2,lasthigh_temp%100/10);
	OLED_PrintNum(60,2,lasthigh_temp%10);
	
	if(key_value==6)
	{
		lasthigh_temp ++;
		key_value =0;	
	}
	if(key_value ==7)
	{
		lasthigh_temp --;
		key_value =0;
	}

}
	







