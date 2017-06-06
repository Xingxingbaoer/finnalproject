#include "24c02.h"

uint8_t AT_Key_=0;
////////////////////////////////////////////////////////
//24c02����ר����ʱ
////////////////////////////////////////////////////////
void delay_i2c(uint8_t t)
{
	uint16_t i,j;
	for(i=0;i<50000;i++)
		for(j=0;j<t;j++);
}

////////////////////////////////////////////////////////
//24c02д��һ���ֽ�
////////////////////////////////////////////////////////
void AT24C02_WriteOneByte(uint8_t WriteAddr, uint8_t DataToWrite)
{				  
  I2C_Send_Ctrl(0XA0);   
	I2C_Send_Byte(WriteAddr);	 //���͵�ַ 										  		   
	I2C_Send_Byte(DataToWrite);     //�����ֽ�							   		    	   
  I2C_Stop();//����һ��ֹͣ���� 
	delay_i2c(4);// �����ʱ���Բ���ȥ��	 
}

////////////////////////////////////////////////////////
//24c02��ȡһ���ֽ�
////////////////////////////////////////////////////////
uint8_t AT24C02_ReadOneByte(uint8_t ReadAddr)
{				  
	uint8_t temp=0;
			  	    																 
	I2C_Send_Ctrl(0XA0); 	 
  I2C_Send_Byte(ReadAddr);   //���͵�ַ    	 	   
	I2C_Send_Ctrl(0XA1);			   
  temp=I2C_Recieve_Byte();	   
  I2C_Stop();//����һ��ֹͣ����
		    
	return temp;
}

////////////////////////////////////////////////////////
//24c02�������� ��ȡ��ַ����ȡ�ֽ���
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
//24c02����д�� д���ַ��д���ֽڣ�д���ֽ���
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
//���24c02�Ƿ����
////////////////////////////////////////////////////////	
uint8_t AT24C02_Check(void)
{
	uint8_t temp;
	temp = AT24C02_ReadOneByte(0x00);	 // ���ֽ�		   
	if(temp==0x88)return 0;		   
	else//�ų���һ�γ�ʼ�������
	{
		AT24C02_WriteOneByte(0x00,0x88);
	  temp=AT24C02_ReadOneByte(0x00);	  
		if(temp==0X88)return 0;
	}
	return 1;											  
}
