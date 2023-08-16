/*
 * DCMotor.c
 *
 * Created: 2023/8/11 12:54:27 AM
 *  Author: Ahmed Adel
 */ 

#include "DCMotor.h"

void DcMotor_Init(void)
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	
	PWM0_Init();
}

void DcMotor_SetDir(DC_MOTOR_DIR Dir)
{
	switch(Dir)
	{
		case CLOCK_WISE_DIR:
		
		DIO_SetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_HIGH);
		DIO_SetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
		
		break;
		
		case ANTI_CLOCK_WISE_DIR:
		
		DIO_SetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);
		
		break;
		
		default:
		break;
	}
}

void DcMotor_SetSpeed(uint8 speed)
{
	PWM0_Generate((speed*10));
}

void DcMotor_Start(void)
{
	PWM0_Start();
}

void DcMotor_Stop(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN5, DIO_PIN_LOW);
	DIO_SetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
}