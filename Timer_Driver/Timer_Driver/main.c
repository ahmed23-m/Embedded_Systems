/*
 * Timer_Driver.c
 *
 * Created: 2023/8/8 1:39:04 AM
 * Author : Ahmed Adel
 */ 

#define F_CPU 16000000
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "Timer.h"
#include "LED.h"



extern uint8  Init_Value;
extern uint32  Number_Of_OverFlows;



int main(void)
{
	LED_Init(RED);
	LED_Init(GREEN);
	LED_Init(BLUE);
	LED_Init(YELLOW);
	
	//-- Timer0 --//
	/*Timer0_Init();
	Timer0_SetDelay(1000);
	Timer0_Start();*/

	Timer1_Init();
	Timer1_SetDelay(1000);
	Timer1_Start();
	
    while (1) 
    {
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint32 counter = 0;
	
	counter++;
	
	if(counter == Number_Of_OverFlows)
	{
		TCNT0 = Init_Value;
		
		counter = 0 ;
		
		//(*ptr)(RED);
		LED_Toggle(RED);
		_delay_ms(400);
		LED_Toggle(GREEN);
		_delay_ms(400);
		LED_Toggle(BLUE);
		_delay_ms(400);
		LED_Toggle(YELLOW);
		
	}
}

ISR(TIMER1_COMPA_vect)
{
	static Counter = 0;
	
	Counter++;
	
	if(Counter == 1)
	{
		Counter = 0;
		
		LED_Toggle(RED);
		_delay_ms(400);
		LED_Toggle(GREEN);
		_delay_ms(400);
		LED_Toggle(BLUE);
		_delay_ms(400);
		LED_Toggle(YELLOW);
	}
}
