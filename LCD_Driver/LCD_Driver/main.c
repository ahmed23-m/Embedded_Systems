/*
 * LCD_Driver.c
 *
 * Created: 7/24/2023 6:51:12 AM
 * Author : Ahmed Adel
 */ 

#include "LCD.h"

int main(void)
{
	LCD_Init();
	LCD_Clear();
	LCD_WriteString("Hello World");
	
    /* Replace with your application code */
    while (1) 
    {
    }
	
}

