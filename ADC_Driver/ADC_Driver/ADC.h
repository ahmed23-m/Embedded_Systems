/*
 * ADC.h
 *
 * Created: 2023/8/7 5:33:33 PM
 *  Author: Ahmed Adel
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Atmega_Registers.h"
#include "BIT_MATH.h"
#include "ADC_Config.h"


#define ADC_VREF_AVCC			0

#define ADC_CHANNEL_1			1

#define ADC_AUTO_TRIGGER		0

#define ADC_RIGHT_ADJUST		0

#define ADC_LEFT_ADJUST			1

#define ADC_PRESC_128			0

#define ADC_INTERRUPT_ENABLE	0

#define ADC_INTERRUPT_DISABLE	1


void ADC_Init(void);

void ADC_Read(uint16* Value);

#endif /* ADC_H_ */