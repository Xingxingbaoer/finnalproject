#include "24c02.h"

uint8_t AT_Key_=0;
////////////////////////////////////////////////////////
//24c02部分专用延时
////////////////////////////////////////////////////////
void delay_i2c(uint8_t t)
{
	uint16_t i,j;
	for(i=0;i<50000;i++)
		for(j=0;j<t;j++);
}

////////////////////////////////////////////////////////
//24c02写入一个字节
////////////////////////////////////////////////////////
void AT24C02_WriteOneByte(uint8_t WriteAddr, uint8_t DataToWrite)
{				  
  I2C_Send_Ctrl(0XA0);   
	I2C_Send_Byte(WriteAddr);	 //发送地址 										  		   
	I2C_Send_Byte(DataToWrite);     //发送字节							   		    	   
  I2C_Stop();//产生一个停止条件 
	delay_i2c(4);// 这个延时绝对不能去掉	 
}

////////////////////////////////////////////////////////
//24c02读取一个字节
////////////////////////////////////////////////////////
uint8_t AT24C02_ReadOneByte(uint8_t ReadAddr)
{				  
	uint8_t temp=0;
			  	    																 
	I2C_Send_Ctrl(0XA0); 	 
  I2C_Send_Byte(ReadAddr);   //发送地址    	 	   
	I2C_Send_Ctrl(0XA1);			   
  temp=I2C_Recieve_Byte();	   
  I2C_Stop();//产生一个停止条件
		    
	return temp;
}

////////////////////////////////////////////////////////
//24c02连续读出 读取地址，读取字节数
////////////////////////////////////////////////////////
void AT24C02_Read(uint8_t ReadAddr,uint8_t *Buffer,uint16_t Num)
{
	while(Num)
	{
		*Buffer++=AT24C02_ReadOneByte(ReadAddr++);	
		Num--;
	}
}  

////////////////////////////////////////////////////////
//24c02连续写入 写入地址，写入字节，写入字节数
////////////////////////////////////////////////////////
void AT24C02_Write(uint8_t WriteAddr,uint8_t *Buffer,uint16_t Num)
{
	while(Num--)
	{
		AT24C02_WriteOneByte(WriteAddr,*Buffer);
		WriteAddr++;
		Buffer++;
	}
}

////////////////////////////////////////////////////////
//检测24c02是否存在
////////////////////////////////////////////////////////	
uint8_t AT24C02_Check(void)
{
	uint8_t temp;
	temp = AT24C02_ReadOneByte(0x00);	 // 读字节		   
	if(temp==0x88)return 0;		   
	else//排除第一次初始化的情况
	{
		AT24C02_WriteOneByte(0x00,0x88);
	  temp=AT24C02_ReadOneByte(0x00);	  
		if(temp==0X88)return 0;
	}
	return 1;											  
}
