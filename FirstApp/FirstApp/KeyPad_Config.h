/*
 * KeyPad_Config.h
 *
 * Created: 7/25/2023 8:08:09 AM
 *  Author: Ahmed Adel
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO.h"

//Row & Col are on different Ports
#define KEYPAD_ROW_PORT DIO_PORTC
#define KEYPAD_COL_PORT DIO_PORTD

#define KEYPAD_COL_0 DIO_PIN7
#define KEYPAD_COL_1 DIO_PIN6
#define KEYPAD_COL_2 DIO_PIN5
#define KEYPAD_COL_3 DIO_PIN3

#define KEYPAD_ROW_0 DIO_PIN5
#define KEYPAD_ROW_1 DIO_PIN4
#define KEYPAD_ROW_2 DIO_PIN3
#define KEYPAD_ROW_3 DIO_PIN2


#endif /* KEYPAD_CONFIG_H_ */