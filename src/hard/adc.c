#include "lpc11xx.h"
#include "adc.h"


/*****************************************/
/* º¯ÊýÃû³Æ£º³õÊ¼»¯ADC¿Ú                 */
/*****************************************/
void ADC_Init(uint8_t Channel)
{
	if(Channel>7) return;
	LPC_SYSCON->PDRUNCFG &= ~(0x1<<4);        // ADCÄ£¿éÉÏµç
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<13);     // Ê¹ÄÜADCÊ±ÖÓ
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);     // Ê¹ÄÜIOCONÊ±ÖÓ
	switch(Channel)
	{
		case 0: // Í¨µÀ0ÅäÖÃ set channel 0
			LPC_IOCON->R_PIO0_11 &= ~0x07;              // 
			LPC_IOCON->R_PIO0_11 |= 0x02;               // °ÑP0.11Òý½ÅÉèÖÃÎªAD0¹¦ÄÜ
			LPC_IOCON->R_PIO0_11 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->R_PIO0_11 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		case 1:  // Í¨µÀ1ÅäÖÃ set channel 1
			LPC_IOCON->R_PIO1_0 &= ~0x07;              // 
			LPC_IOCON->R_PIO1_0 |= 0x02;               // °ÑP1.0Òý½ÅÉèÖÃÎªAD1¹¦ÄÜ
			LPC_IOCON->R_PIO1_0 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->R_PIO1_0 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		case 2:  // Í¨µÀ2ÅäÖÃ set channel 2
			LPC_IOCON->R_PIO1_1 &= ~0x07;              // 
			LPC_IOCON->R_PIO1_1 |= 0x02;               // °ÑP1.1Òý½ÅÉèÖÃÎªAD2¹¦ÄÜ
			LPC_IOCON->R_PIO1_1 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->R_PIO1_1 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		case 3:  // Í¨µÀ3ÅäÖÃ set channel 3
			LPC_IOCON->R_PIO1_2 &= ~0x07;              // 
			LPC_IOCON->R_PIO1_2 |= 0x02;               // °ÑP1.2Òý½ÅÉèÖÃÎªAD3¹¦ÄÜ
			LPC_IOCON->R_PIO1_2 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->R_PIO1_2 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		case 4:  // Í¨µÀ4ÅäÖÃ set channel 4
			LPC_IOCON->SWDIO_PIO1_3 &= ~0x07;              // 
			LPC_IOCON->SWDIO_PIO1_3 |= 0x02;               // °ÑP1.3Òý½ÅÉèÖÃÎªAD4¹¦ÄÜ
			LPC_IOCON->SWDIO_PIO1_3 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->SWDIO_PIO1_3 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		case 5:  // Í¨µÀ5ÅäÖÃ set channel 5
			LPC_IOCON->PIO1_4 &= ~0x07;              // 
			LPC_IOCON->PIO1_4 |= 0x01;               // °ÑP1.4Òý½ÅÉèÖÃÎªAD5¹¦ÄÜ
			LPC_IOCON->PIO1_4 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->PIO1_4 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		case 6:  // Í¨µÀ6ÅäÖÃ set channel 6
			LPC_IOCON->PIO1_10 &= ~0x07;              // 
			LPC_IOCON->PIO1_10 |= 0x01;               // °ÑP1.10Òý½ÅÉèÖÃÎªAD6¹¦ÄÜ
			LPC_IOCON->PIO1_10 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->PIO1_10 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		case 7:  // Í¨µÀ7ÅäÖÃ set channel 7
			LPC_IOCON->PIO1_11 &= ~0x07;              // 
			LPC_IOCON->PIO1_11 |= 0x01;               // °ÑP1.11Òý½ÅÉèÖÃÎªAD7¹¦ÄÜ
			LPC_IOCON->PIO1_11 &= ~(3<<3) ;           // È¥µôÉÏÀ­ºÍÏÂÀ­µç×è
			LPC_IOCON->PIO1_11 &= ~(1<<7) ;           // Ä£ÄâÊäÈëÄ£Ê½
			break;
		default:break;
	}
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);    // ¹Ø±ÕIOCONÊ±ÖÓ
	LPC_ADC->CR = (1<<Channel)|                /* bit7:bit0   Ñ¡ÔñÍ¨µÀChannel*/
										(24<<8)|                     /* bit15:bit8  °Ñ²ÉÑùÊ±ÖÓÆµÂÊÉèÖÃÎª2MHz 50/(24+1)*/
	                  (1<<16);                    /* Ó²¼þÉ¨ÃèÄ£Ê½ */
}

/********************************************/
/* º¯Êý¹¦ÄÜ£º¶ÁÈ¡µçÑ¹Öµ£¨AD7£©              */
/* ³ö¿Ú²ÎÊý£ºadc_value, ¶Áµ½µÄµçÑ¹Öµ        */
/********************************************/
//uint32_t ADC_Read(uint8_t Channel)
//{
//	uint32_t adc_value=0;

//	adc_value = ((LPC_ADC->DR[Channel]>>6)&0x3FF);		
//	adc_value = (adc_value*Vref)/1024; // ×ª»»ÎªÕæÕýµÄµçÑ¹Öµ

//	return adc_value;	  // ·µ»Ø½á¹û
//}


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*º¯Êý¹¦ÄÜ£º ¼ÆËãNTCµÄµç×èÖµ£¨AD7£                       ©*/
//////////////////////////////////////////////////////////
uint32_t NTC_Read(uint8_t Channel)
{
	
	uint32_t adc_value,R_ntc=0;
	 

	adc_value = ((LPC_ADC->DR[Channel]>>6)&0x3FF);		
	adc_value = (adc_value*Vref)/1024; // ×ª»»ÎªÕæÕýµÄµçÑ¹Öµ
	
	
	R_ntc =(adc_value * 10000)/(3300-adc_value);
	
	
	return R_ntc;



}

