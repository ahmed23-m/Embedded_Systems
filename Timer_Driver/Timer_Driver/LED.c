/*
 * LED.c
 *
 * Created: 7/21/2023 8:00:08 PM
 *  Author: Ahmed Adel
 */ 

#include "LED.h"

void LED_Init(uint8 Color){
	switch(Color)
	{
		case RED:
		DIO_SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);
		break;
		case GREEN:
		DIO_SetPinDir(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
		break;
		case BLUE:
		DIO_SetPinDir(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
		break;
		case YELLOW:
		DIO_SetPinDir(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
		break;
		default:
		break;
	}
	
}
void LED_ON(uint8 Color){
	switch(Color)
	{
		case RED:
		DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
		break;
		case GREEN:
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		break;
		case BLUE:
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		break;
		case YELLOW:
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
		break;
		default:
		break;
	}
}
void LED_OFF(uint8 Color){
	switch(Color)
	{
		case RED:
		DIO_SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
		break;
		case GREEN:
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		break;
		case BLUE:
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		break;
		case YELLOW:
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
		break;
		default:
		break;
	}
}
void LED_Toggle(uint8 Color){
	switch(Color)
	{
		case RED:
		DIO_TogglePin(DIO_PORTB,DIO_PIN7);
		break;
		case GREEN:
		DIO_TogglePin(DIO_PORTA,DIO_PIN4);
		break;
		case BLUE:
		DIO_TogglePin(DIO_PORTA,DIO_PIN5);
		break;
		case YELLOW:
		DIO_TogglePin(DIO_PORTA,DIO_PIN6);
		break;
		default:
		break;
	}
}