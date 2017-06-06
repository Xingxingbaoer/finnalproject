#ifndef   __NXPLPC11XX_UART_H__
#define   __NXPLPC11XX_UART_H__

#include "LPC11xx.h"
extern uint8_t Recived_data; // �����ֽ�
extern void UART_Init(void);
extern void UART_init(uint32_t baudrate);  // ��ʼ������
extern void UART_SendStr(char *pucStr);
extern void UART_SendByte(uint8_t ucDat);
extern uint8_t UART_recive(void);   // ���ڽ����ֽ�����
extern void UART_send_byte(uint8_t byte); // ���ڷ����ֽ�����
extern void UART_send(uint8_t *Buffer, uint32_t Length); // ���ڷ�����������

#endif





