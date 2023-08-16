/*
 * UART.c
 *
 * Created: 2023/8/14 5:16:06 PM
 *  Author: Ahmed Adel
 */ 

#include "UART.h"

void UART_Init(void)
{
	uint32 BR_Value = 0;
	
	DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	
	UCSRB |= 0x18;
	UCSRC |= 0x86;
	
	//BR_Value = (16000000/16*(9600)) - 1; //! remove 00 to avoide overflow
	BR_Value = (160000/ (16 * (96) )) - 1;
	
	UBRRL = BR_Value;
}

void UART_SendByte(uint8 Data)
{
	UDR = Data;
	
	while(GET_BIT(UCSRA, 5)==0);
}

void UART_SendString(uint8* Str)
{
	uint8 i = 0;
	
	while(Str[i] != '\0')
	{
		UART_SendByte(Str[i]);
		i++;
	}
}

uint8 UART_ReceiveByte(void)
{
	uint8 data = 0;
	
	while(GET_BIT(UCSRA, 7)==0);
	
	data = UDR;
	
	return data;
}

uint8* UART_ReceiveString(void)
{
	
}