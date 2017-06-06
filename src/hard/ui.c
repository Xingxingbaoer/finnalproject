#include "LPC11xx.h"
#include "stdio.h"
#include "string.h"
#include "KEY.h"
#include "temperature.h"
#include "delay.h"
#include "oled.h"
#include "ui.h"
#include "24c02.h"
#include "uart.h"
extern int  	key_value  ;
extern  float low_temp ;
extern  float high_temp ;
extern  uint32_t  k,t;
extern	int   lastlow_temp ;
extern	int   lasthigh_temp ; 

uint8_t Arrow = 2,	chonum, scrnum = 0;

uint8_t AR[]="=>";//显示箭头
uint8_t AC[]="  ";//消除箭头
int i=0;

typedef struct 
{
	uint8_t num;
	uint8_t number[2];
	uint8_t title[20];
	uint8_t choose1[20];
	uint8_t choose2[20];
	uint8_t choose3[20];
	uint8_t choose4[20];
	uint8_t choose5[20];
	uint8_t choose6[20];
	uint8_t choose7[20];
}screen[1];
static screen scr[10]=
{
//{???,"???","标题",      					 "菜单1",               "菜单2",           			  "菜单3",           	    "菜单4",             		"菜单5",            		 "菜单6"		},
	{0,"0","    Yu_Xuan    ",   "     start     ",   "    Setting    ",   "       _       ",   "       _       ",   "      MC       ",   "       _      "},   
  {1,"1","start          ",   "    N_temp     ",   "       -       ",   "       _       ",   "       _       ",   "       _       ",   "       -       "},
  {2,"2","setting        ",   "    lowtemp    ",   "   higetemp   ",   "       _       ",   "       -       ",   "       -       ",   "       -       "},
  {3,"3","       -       ",   "       _       ",   "       _       ",   "       _       ",   "       -       ",   "       -       ",   "       -       "},
  {4,"4","       -       ",   "       _       ",   "       _       ",   "       _       ",   "       -       ",   "       -       ",   "       -       "},
  {5,"5","MC             ",   "  15160200122  ",   "    xuzhiyi    ",   "  15160200125  ",   "   huahengxin  ",   "       -       ",   "       -       "},
  {6,"6","       -       ",   "       _       ",   "       _       ",   "       _       ",   "       _       ",   "       -       ",   "       -       "},
};
void printscreen(uint8_t i)
{
	OLED_P6x8Str(0,0,scr[i]->title );
	OLED_P6x8Str(16,2,scr[i]->choose1);
  OLED_P6x8Str(16,3,scr[i]->choose2);
	OLED_P6x8Str(16,4,scr[i]->choose3);
	OLED_P6x8Str(16,5,scr[i]->choose4);
	OLED_P6x8Str(16,6,scr[i]->choose5);
	OLED_P6x8Str(16,7,scr[i]->choose6);
	
}
uint8_t  UI(void)
{
	
	
	
	OLED_P6x8Str(0,Arrow,AR );
	
	printscreen (scrnum);
	
	switch(key_value )
	{
		case 6:                                   
    OLED_P6x8Str(0,Arrow,AC);
    Arrow--;
    if(Arrow < 2) Arrow=7;
    OLED_P6x8Str(0,Arrow,AR);
    key_value = 0;
    break;
    
  case 7:                                   
    OLED_P6x8Str(0,Arrow,AC);
    Arrow++;
    if(Arrow > 7) Arrow=2;
    OLED_P6x8Str(0,Arrow,AR);
    key_value = 0;
    break;
    
  case 8:                                   
    {
      OLED_CLS();
      OLED_P6x8Str(0,Arrow,AC);             
      if(scrnum!=0)                          
      {
        chonum=scrnum*10+Arrow-1;           
      }
      else
      {
        scrnum=Arrow-1;                     
        chonum=Arrow-1;
      }
      key_value = 0;
      break;
    }
  case 9:                                   
    {
      OLED_P6x8Str(0,Arrow,AC);
      scrnum=0;
      key_value = 0;
      OLED_CLS();
      break;
    }
  case 0:
    break;
	}
	
		switch(chonum)
    {

			case 11:UART_send("N_temp:",8);
							OLED_Print(5, 0, "now temp:");
			        while(key_value != 9)
							{
								temp();
								OLED_PrintNum(20,2,t%1000/100);
								OLED_PrintNum(30,2,t%100/10);
								OLED_P6x8Str(37,2,".");
								OLED_PrintNum(40,2,t%10/1);
								OLED_P6x8Str(50,2,"C'");
								
							}
			
							
							break;
      case 12:break;
      case 13:break;
      case 14:break;

			case 21:UART_send("lowtemp:",8);
							lastlow_temp=low_temp;
							while(key_value != 9)
							{
								lowtemp_setting();
								if(key_value == 9)
								{
									AT24C02_WriteOneByte(0x01,lastlow_temp);
								  low_temp=AT24C02_ReadOneByte(0x01);
									lastlow_temp=low_temp;
									OLED_CLS();
								}
							}
						  
						  break;
			case 22:UART_send("higetemp:",9);
							lasthigh_temp=high_temp;
							while(key_value != 9)
							{
								hightemp_setting();
								if(key_value == 9)
								{
									AT24C02_WriteOneByte(0x02,lasthigh_temp);
								  high_temp=AT24C02_ReadOneByte(0x02);
									lasthigh_temp=high_temp;
									OLED_CLS();
								}
							}
							
							 break;
			case 23:
							
								
							break;

    }
return 0;
	
}	
