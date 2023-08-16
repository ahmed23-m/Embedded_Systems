/*
 * KeyPad.c
 *
 * Created: 7/25/2023 8:08:23 AM
 *  Author: Ahmed Adel
 */ 
#include "KeyPad.h"
#define  F_CPU 16000000
#include <util/delay.h>

//INIT & FINAL Depends on Pins
#define Col_INIT  7
#define Col_FINAL 3

#define Row_INIT  5
#define Row_FINAL 2

//Values of The KeyPad
const uint8 KeyPad_Values[4][4] = { {'1' , '2' , '3' , '4'},
									{'5' , '6' , '7' , '8'},
									{'9' , 'a' , 'b' , 'c'},
									{'d' , 'e' , 'f' , 'g'}};

void KeyPad_Init(void)
{
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL_0, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL_1, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL_2, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL_3, DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW_0, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW_1, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW_2, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW_3, DIO_PIN_INPUT);
	
	Set_PullUp(KEYPAD_ROW_PORT, KEYPAD_ROW_0);
	Set_PullUp(KEYPAD_ROW_PORT, KEYPAD_ROW_1);
	Set_PullUp(KEYPAD_ROW_PORT, KEYPAD_ROW_2);
	Set_PullUp(KEYPAD_ROW_PORT, KEYPAD_ROW_3);

	DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_0, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_1, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_2, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_3, DIO_PIN_HIGH);
	
}

uint8 KeyPad_GetValue(void)
{
	uint8 LOC_Column = 0;
	uint8 LOC_Row = 0;
	uint8 Value = 0;
	uint8 Temp = 0;
	
	for( LOC_Column = Col_INIT ; LOC_Column >= Col_FINAL ; LOC_Column-- ) //Decrement Because of ports [7 -> 2]
	{
		if(LOC_Column == 4)
		{
			continue;
		}
		
		DIO_SetPinValue(KEYPAD_COL_PORT, LOC_Column, DIO_PIN_LOW);
		
		for( LOC_Row = Row_INIT ; LOC_Row >= Row_FINAL ; LOC_Row-- )
		{
			DIO_ReadPin(KEYPAD_ROW_PORT, LOC_Row, &Temp);
			
			if(!Temp)
			{
				Value = KeyPad_Values[Row_INIT - LOC_Row][Col_INIT - LOC_Column];
				
				while(!Temp)
				{
					DIO_ReadPin(KEYPAD_ROW_PORT, LOC_Row, &Temp);
				}
				
				_delay_ms(10);//Solving Bouncing Problem ( DeBouncing )
				
			}
		}
		
		DIO_SetPinValue(KEYPAD_COL_PORT, LOC_Column, DIO_PIN_HIGH);
	}
	
	return Value;
}