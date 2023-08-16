/*
 * LCD.h
 *
 * Created: 7/24/2023 6:54:17 AM
 *  Author: Ahmed Adel
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Config.h"


void LCD_Init(void);

void LCD_WriteCommand(uint8 CMD);

void LCD_WriteData(uint8 DATA);

void LCD_GoTO(uint8 Row,uint8 Col);

void LCD_WriteString(uint8* Str);

void LCD_Clear(void);


#endif /* LCD_H_ */