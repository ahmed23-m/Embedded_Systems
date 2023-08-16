/*
 * Atmega_Registers.h
 *
 * Created: 7/21/2023 3:54:46 PM
 *  Author: Ahmed Adel
 */ 


#ifndef ATMEGA_REGISTERS_H_
#define ATMEGA_REGISTERS_H_

#include "STD.h"

/******************************[ DIO_PORT_A ]**********************************/

#define DDRA (*(volatile uint8*)(0x3A))
#define PORTA (*(volatile uint8*)(0x3B))
#define PINA (*(volatile uint8*)(0x39))

/******************************[ DIO_PORT_B ]**********************************/

#define DDRB (*(volatile uint8*)(0x37))
#define PORTB (*(volatile uint8*)(0x38))
#define PINB (*(volatile uint8*)(0x36))

/******************************[ DIO_PORT_C ]**********************************/

#define DDRC (*(volatile uint8*)(0x34))
#define PORTC (*(volatile uint8*)(0x35))
#define PINC (*(volatile uint8*)(0x33))

/******************************[ DIO_PORT_D ]**********************************/

#define DDRD (*(volatile uint8*)(0x31))
#define PORTD (*(volatile uint8*)(0x32))
#define PIND (*(volatile uint8*)(0x30))

/*******************************************************************************/


/******************************[ External_Interrupt ]***************************/

#define SREG (*(volatile uint8*)(0x5F))

#define GICR (*(volatile uint8*)(0x5B))

#define GIFR (*(volatile uint8*)(0x5A))

#define MCUCR (*(volatile uint8*)(0x55))

#define MCUCSR (*(volatile uint8*)(0x54))


/*******************************************************************************/


/******************************[ ADC ]***************************/

#define ADMUX (*(volatile uint8*)(0x27))

#define ADCSRA (*(volatile uint8*)(0x26))

#define ADCH (*(volatile uint8*)(0x25))

#define ADCL (*(volatile uint8*)(0x24))

#define ADC_ADJUST (*(volatile uint16*)(0x24))

#define SFIOR (*(volatile uint8*)(0x50))


/*******************************************************************************/
#endif /* ATMEGA_REGISTERS_H_ */