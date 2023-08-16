/*
 * LED.h
 *
 * Created: 7/21/2023 7:59:17 PM
 *  Author: Ahmed Adel
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"

#define RED     0
#define GREEN   1
#define BLUE    2
#define YELLOW  3

void LED_Init(uint8 Color);
void LED_ON(uint8 Color);
void LED_OFF(uint8 Color);
void LED_Toggle(uint8 Color);


#endif /* LED_H_ */