/*
 * DCMotor.h
 *
 * Created: 2023/8/11 12:54:40 AM
 *  Author: Ahmed Adel
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "Timer.h"
#include "DIO.h"


typedef enum
{
	CLOCK_WISE_DIR,
	ANTI_CLOCK_WISE_DIR
}DC_MOTOR_DIR;



void DcMotor_Init(void);

void DcMotor_SetDir(DC_MOTOR_DIR Dir);

void DcMotor_SetSpeed(uint8 speed);

void DcMotor_Start(void);

void DcMotor_Stop(void);

#endif /* DCMOTOR_H_ */