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


/******************************[ Timer0 ]***************************/

#define TCNT0 (*(volatile uint8*)(0x52))

#define TCCR0 (*(volatile uint8*)(0x53))

#define OCR0 (*(volatile uint8*)(0x5C))

#define TIMSK (*(volatile uint8*)(0x59))


/*******************************************************************************/


/******************************[ Timer1 ]***************************/

#define TCCR1A (*(volatile uint8*)(0x4F))

#define TCCR1B (*(volatile uint8*)(0x4E))

#define OCR1A (*(volatile uint16*)(0x4A))

#define ICR1 (*(volatile uint16*)(0x46))

/*******************************************************************************/


/******************************[ UART ]***************************/

#define UBRRH (*(volatile uint8*)(0x40))

#define UBRRL (*(volatile uint8*)(0x29))

#define UCSRA (*(volatile uint8*)(0x2B))

#define UCSRB (*(volatile uint8*)(0x2A))

#define UCSRC (*(volatile uint8*)(0x40))

#define UDR (*(volatile uint8*)(0x2C))

/*******************************************************************************/


/******************************[ SPI ]***************************/
/* Because SPI Registers are in sequence we will use struct in implementation */

typedef struct
{
	uint8 SPR0 : 1;
	uint8 SPR1 : 1;
	uint8 CPHA : 1;
	uint8 CPOL : 1;
	uint8 MSTR : 1;
	uint8 DORD : 1;
	uint8 SPE : 1;
	uint8 SPIE : 1;	
}SPCR_REG;

typedef struct
{
	SPCR_REG SPCR;
	uint8 SPSR;
	uint8 SPDR;
}SPI_REG;

#define SPI ((volatile SPI_REG*)(0x2D))

/*******************************************************************************/
#endif /* ATMEGA_REGISTERS_H_ */