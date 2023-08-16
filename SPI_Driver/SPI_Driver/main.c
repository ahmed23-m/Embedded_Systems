/*
 * SPI_Driver.c
 *
 * Created: 2023/8/15 5:40:02 AM
 * Author : Ahmed Adel
 */ 
#include "SPI.h"
#include "LED.h"
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
	uint8 Received_Data = 0;
	uint8 Trans_Data = 2;
	
	SPI_Master_Init();
	SPI_InitTransmission();
	_delay_ms(1000);//Master needs 1000ms delay
    
    while (1) 
    {
		Received_Data = SPI_Transive(Trans_Data);
		
		if(Received_Data == 2)
		{
			//Toggle led
			Received_Data = 0;	
		}
		_delay_ms(1000);
    }
}

