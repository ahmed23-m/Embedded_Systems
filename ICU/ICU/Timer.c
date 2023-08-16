/*
 * Timer.c
 *
 * Created: 2023/8/8 1:45:16 AM
 *  Author: Ahmed Adel
 */ 

#include "Timer.h"

//#define NULL ((void*)(0))
//void (*ptr)(void) = NULL;

uint8  Init_Value = 0;
uint32 Timer0_OVF = 0;


volatile uint32 Timer1_OVF = 0;

volatile uint32 ICU_CaptValue_1 = 0;
volatile uint32 ICU_CaptValue_2 = 0;
volatile uint32 ICU_CaptValue_3 = 0;

volatile uint8 Capture_Counter  = 0;

void Timer0_Init(void)
{
	TCCR0 |= 0x00;
	
	TIMSK |= 0x01;
	
	SREG  |= 0x80;
}

void Timer0_Start(void)
{
	TCCR0 |= 0x05;
}

void Timer0_Stop(void)
{
	CLR_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
}

void Timer0_SetDelay(uint32 Delay_Ms)
{
	uint8 Tick_Time = (1024 / 16);
	
	uint32 Total_Ticks = (Delay_Ms * 1000) / Tick_Time;
	
	Timer0_OVF = Total_Ticks / 256;
	
	Init_Value = 256 - (Total_Ticks * 256);
	
	TCNT0 = Init_Value;
	
	Timer0_OVF++;
}


void Timer1_Init(void)
{
	TCCR1B |= 0x08;
	
	TIMSK  |= 0x10;
	
	SREG   |= 0x80;
}

void Timer1_Start(void)
{
	TCCR1B |= 0x05;
}

void Timer1_Stop(void)
{
	CLR_BIT(TCCR1B , 0);
	CLR_BIT(TCCR1B , 1);
	CLR_BIT(TCCR1B , 2);
}

void Timer1_SetDelay(uint32 Delay_Ms)
{
	if(Delay_Ms <= 4000)
	{
		uint8 Tick_time = 1024 / 16;
		
		uint32 Number_Of_Ticks = (Delay_Ms * 1000) / Tick_time;
		
		OCR1A = Number_Of_Ticks - 1;
	}
}

/*void Set_CallBack(void(*p)(void))
{
	ptr = p;
}*/

//==Put ISR Here==//


void PWM0_Init(void)
{
	DDRB |= 0x08;
	
	TCCR0 |= 0x68;
}

void PWM0_Generate(uint16 Duty_Cycle)
{
	OCR0 = ((Duty_Cycle * 256) / 100) - 1;
}

void PWM0_Start(void)
{
	TCCR0 |= 0x03;
}



void PWM1_Init(void)
{
	DDRB |= 0x20;	//PD5
	
	TCCR1A |= 0x02;
	TCCR1B |= 0x18;
	
	ICR1 = 1250;	//Set Timer Top value
}

void PWM1_Generate(uint16 Duty_Cycle)
{
	OCR1A = ( (Duty_Cycle * 1250) / 100 ) - 1;
}

void PWM1_Start(void)
{
	TCCR1B |= 0x04;	//Presc 256
}


void ICU_Init(void)
{
	CLR_BIT(DDRD,6);//Pin-6 (ICP) as input
	
	ICR1 = 0x0000;
	TCCR1B |= 0x41;
	
	TIMSK |= 0x24;
	SREG  |= 0x80;// Enable Global Interrupt
}

ISR(TIMER1_CAPT_vect)
{
	Capture_Counter++;
	if(Capture_Counter == 1)
	{
		ICU_CaptValue_1 = ICR1;
		
		Timer1_OVF = 0;
		
		CLR_BIT(TCCR1B,6);	// Detect Falling Edge
	}
	else if (Capture_Counter == 2)
	{
		ICU_CaptValue_2 = ICR1 + (Timer1_OVF * 65535);
		
		SET_BIT(TCCR1B,6);	// Detect Rising Edge
	}
	else if (Capture_Counter == 3)
	{
		ICU_CaptValue_3 = ICR1 + (Timer1_OVF * 65535);
		
		CLR_BIT(TIMSK,5);	// Disable ICU Interrupt
	}
}

ISR(TIMER1_OVF_vect)
{
	Timer1_OVF++;
}