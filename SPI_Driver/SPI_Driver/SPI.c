/*
 * SPI.c
 *
 * Created: 2023/8/15 5:40:33 AM
 *  Author: Ahmed Adel
 */ 
#include "SPI.h"


void SPI_Master_Init(void)
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	
	SPI->SPCR.SPR0 = 1;
	SPI->SPCR.SPR1 = 1;
	SPI->SPCR.MSTR = 1;
	SPI->SPCR.SPE = 1;
}

void SPI_Slavelnit(void)
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	
	SPI->SPCR.SPE = 1;
}

uint8 SPI_Transive(uint8 Tx_data)
{
	uint8 received_data = 0;
	
	SPI->SPDR = Tx_data;
	
	while(GET_BIT(SPI->SPSR , 7) == 0);
	
	received_data = SPI->SPDR;
	
	return received_data;	
}

void SPI_InitTransmission(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
}

void SPI_TerminatTransmission(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}