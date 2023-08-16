/*
 * UART_Driver.c
 *
 * Created: 2023/8/14 5:11:47 PM
 * Author : Ahmed Adel
 */ 

#include "UART.h"


int main(void)
{
	uint8 data = 0;
	
	UART_Init();
	
	//LCD_Init();
	
    while (1) 
    {
		data = UART_ReceiveByte();
		
		if(data)
		{
			//LCD_WriteData(data);
			data = 0;
		}
    }
}

