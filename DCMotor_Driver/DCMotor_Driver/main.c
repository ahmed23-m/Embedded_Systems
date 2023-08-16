/*
 * DCMotor_Driver.c
 *
 * Created: 2023/8/11 12:52:46 AM
 * Author : Ahmed Adel
 */ 

#include "DCMotor.h"
#define  F_CPU 16000000
#include <util/delay.h>

int main(void)
{
    DcMotor_Init();
	
	DcMotor_SetDir(CLOCK_WISE_DIR);
	DcMotor_SetSpeed(5);
	/*for(uint8 i =1;i<=10;i++)
	{
		DcMotor_SetSpeed(i);
		_delay_ms(4000);
	}*/
	
	
	DcMotor_Start();
	
    while (1) 
    {
    }
}

