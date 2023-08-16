/*
 * LCD.c
 *
 * Created: 7/24/2023 6:54:29 AM
 *  Author: Ahmed Adel
 */ 

#include "LCD.h"
#define F_CPU 16000000
//#define F_CPU 8000000
#include <util/delay.h>


void LCD_Init(void)
{
	#if LCD_MODE == 8
	
	DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	//DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_DATA_PORT, DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0E);
	LCD_WriteCommand(0x01);
	
	_delay_ms(5);
	
	#elif LCD_MODE == 4
	
	DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	//DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D4, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D5, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D6, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D7, DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	
	//Initialize LCD as 4-Bit Mode
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
	_delay_ms(5);
	
	#endif
}

void LCD_WriteCommand(uint8 CMD)
{
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	//DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	PORTB = (CMD & 0XF0) | (PORTB & 0X0F);
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	PORTB = (CMD << 4) | (PORTB & 0X0F);
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteData(uint8 DATA)
{
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	//DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	PORTB = (DATA & 0XF0) | (PORTB & 0X0F);
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	PORTB = (DATA << 4) | (PORTB & 0X0F);
	
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_GoTO(uint8 Row,uint8 Col)
{
	uint8 Pos[4] = {0x80, 0xC0, 0x94, 0xD4};
		
	LCD_WriteCommand(Pos[Row] + Col);
	
}

void LCD_WriteString(uint8* Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_WriteData(Str[i]);
		i++;
	}
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}