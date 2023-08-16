/*
 * ServoMotor.c
 *
 * Created: 2023/8/12 9:21:57 PM
 *  Author: Ahmed Adel
 */ 

#include "ServoMotor.h"


void ServoMotor_Init(void)
{
	PWM1_Init();
	PWM1_Start();
}

void ServoMotor_SetDegree(uint8 Degree)
{
	uint16 Duty_Cycle = 0;
	
	Duty_Cycle = 5 + (Degree * .36);
	
	PWM1_Generate(Duty_Cycle);
}