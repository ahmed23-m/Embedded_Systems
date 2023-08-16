/*
 * Timer.h
 *
 * Created: 2023/8/8 1:44:32 AM
 *  Author: Ahmed Adel
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "Atmega_Registers.h"
#include "BIT_MATH.h"



void Timer0_Init(void);

void Timer0_Start(void);

void Timer0_Stop(void);

void Timer0_SetDelay(uint32 Delay_Ms);


void PWM0_Init(void);

void PWM0_Generate(uint16 Duty_Cycle);

void PWM0_Start(void);


//void Set_CallBack(void(*p)(void));

void Timer1_Init(void);

void Timer1_Start(void);

void Timer1_Stop(void);

void Timer1_SetDelay(uint32 Delay_Ms);


void PWM1_Init(void);

void PWM1_Generate(uint16 Duty_Cycle);

void PWM1_Start(void);


#endif /* TIMER_H_ */