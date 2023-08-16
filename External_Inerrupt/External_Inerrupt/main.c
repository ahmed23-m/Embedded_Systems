/*
 * External_Inerrupt.c
 *
 * Created: 2023/8/2 1:56:46 AM
 * Author : Ahmed Adel
 */ 

#include "External_INT.h"
#include "LED.h"
#include <avr/interrupt.h>


int main(void)
{
    ExternalINT0_Init();
	
	LED_Init(RED);
	
    while (1) 
    {
		
    }
}

ISR(INT0_vect)
{
	
	LED_Toggle(RED);
	
}
