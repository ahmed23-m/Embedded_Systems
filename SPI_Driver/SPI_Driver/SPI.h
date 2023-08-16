/*
 * SPI.h
 *
 * Created: 2023/8/15 5:40:45 AM
 *  Author: Ahmed Adel
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_Master_Init(void);

void SPI_Slavelnit(void);

uint8 SPI_Transive(uint8 Tx_data);

void SPI_InitTransmission(void);

void SPI_TerminatTransmission(void);

#endif /* SPI_H_ */