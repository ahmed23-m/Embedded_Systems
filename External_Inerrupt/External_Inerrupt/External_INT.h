/*
 * External_INT.h
 *
 * Created: 2023/8/2 1:59:11 AM
 *  Author: Ahmed Adel
 */ 


#ifndef EXTERNAL_INT_H_
#define EXTERNAL_INT_H_

#include "Atmega_Registers.h"
#include "BIT_MATH.h"
#include "External_INT_Config.h"


#define GLOBAL_INTERRUPT_ENABLE		1
#define GLOBAL_INTERRUPT_DISABLE	0


#define EXTERNAL_INT0				6
#define EXTERNAL_INT1				7
#define EXTERNAL_INT2				5


#define INT0_TRIGGER_LOW_LEVEL				0
#define INT0_TRIGGER_RISING_EDGE			1
#define INT0_TRIGGER_FALLING_EDGE			2
#define INT0_TRIGGER_ANY_LOGICAL_CHANGE		3


#define INT1_TRIGGER_LOW_LEVEL				0
#define INT1_TRIGGER_RISING_EDGE			1
#define INT1_TRIGGER_FALLING_EDGE			2
#define INT1_TRIGGER_ANY_LOGICAL_CHANGE		3


#define INT2_TRIGGER_RISING_EDGE			0
#define INT2_TRIGGER_FALLING_EDGE			1



void SET_GlobalInterrupt(void);

void ExternalINT0_Init(void);

void ExternalINT1_Init(void);

void ExternalINT2_Init(void);



#endif /* EXTERNAL_INT_H_ */