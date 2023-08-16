/*
 * UART.h
 *
 * Created: 2023/8/14 5:15:55 PM
 *  Author: Ahmed Adel
 */ 


#ifndef UART_H_
#define UART_H_

#include "DIO.h"

void UART_Init(void);

void UART_SendByte(uint8 Data);

void UART_SendString(uint8* Str);

uint8 UART_ReceiveByte(void);

uint8* UART_ReceiveString(void);


#endif /* UART_H_ */