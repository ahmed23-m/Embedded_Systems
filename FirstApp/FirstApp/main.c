/*
 * FirstApp.c
 *
 * Created: 7/21/2023 3:51:51 PM
 * Author : Ahmed Adel
 */ 

#define F_CPU 16000000
#include <util/delay.h>
#include "LED.h"
#include "KeyPad.h"

int main(void)
{
	uint8 Button_Value = 0;
	
	//KeyPad Initialization
	KeyPad_Init();
	
	//LED Initialization
	LED_Init(RED);	
	LED_Init(BLUE);
	
	//Buzzer Initialization
	DIO_SetPinDir(DIO_PORTC,DIO_PIN6,DIO_PIN_INPUT);
    /* Replace with your application code */
    while (1) 
    {
		Button_Value = KeyPad_GetValue();
		if (Button_Value)
		{
			for (uint8 i =0;i<6;i++)
			{
				LED_Toggle(RED);
				_delay_ms(1000);
				LED_Toggle(BLUE);
				DIO_TogglePin(DIO_PORTC,DIO_PIN6);
				
			}
		}
		
    }
}

