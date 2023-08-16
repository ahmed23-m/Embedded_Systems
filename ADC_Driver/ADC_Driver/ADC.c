/*
 * ADC.c
 *
 * Created: 2023/8/7 5:34:14 PM
 *  Author: Ahmed Adel
 */ 

#include "ADC.h"



void ADC_Init(void)
{
	#if ADC_VOLTAGE_REFERENCE	==	ADC_VREF_AVCC
	
	CLR_BIT(ADMUX , 7);
	SET_BIT(ADMUX , 6);
	
	#endif

	#if ADC_ADJUST				==	ADC_RIGHT_ADJUST
	
	CLR_BIT(ADMUX , 5);
	
	#endif

	#if ADC_CHANNEL				==	ADC_CHANNEL_1
	
	SET_BIT(ADMUX , 0);
	
	#endif

	#if ADC_CONVERSION_TRIGGER	==	ADC_AUTO_TRIGGER
	
	SET_BIT(ADCSRA , 5);
	
	#endif

	#if ADC_PRESCALER			==	ADC_PRESC_128
	
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	
	#endif

	#if ADC_INTERRUPT_STATE		==	ADC_INTERRUPT_DISABLE
	
	CLR_BIT(ADCSRA , 3);
	
	#endif
	
	//==> ADC Enable
	SET_BIT(ADCSRA , 7);
}

void ADC_Read(uint16* Value)
{
	uint16 Digital_Value = 0;
	//Start Conversion
	SET_BIT(ADCSRA , 6);
	#if ADC_INTERRUPT_STATE == ADC_INTERRUPT_DISABLE
		
	while(!GET_BIT(ADCSRA,4));
	Digital_Value = ADC_ADJUST;
	Value = (Digital_Value*500)/1024;
	
	#endif
}