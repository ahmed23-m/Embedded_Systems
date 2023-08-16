/*
 * ServoMotor_Driver.c
 *
 * Created: 2023/8/12 9:19:23 PM
 * Author : Ahmed Adel
 */ 

#include "ServoMotor.h"


int main(void)
{
    ServoMotor_Init();
	ServoMotor_SetDegree(10);
	//PWM1_Generate(7);
    while (1) 
    {
    }
}

