/*
 * SPI_PRIVATE.h
 *
 *  Created on: Feb 17, 2018
 *      Author: sphinx
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_



#define SPI1_BASE	(struct spi1 *)0x40013000



// SPI1_CR1 BITS

#define  BR   PIN3  //BAUDRATE
#define  MSTR PIN2 //MASTER SELECT
#define  SPE  PIN6 //SPI ENABLE
#define  SSI  PIN8  //INTERNAL SLAVE SELECT
#define  SSM  PIN9  //SLAVE SELECT MANAGEMENT

//SPI_SR BITS
#define  RXNE PIN0
#define  TXE  PIN1

//SPI_1_REGISTERS
struct spi1
{
        volatile U32 SPI_CR1 ;
        volatile U32 SPI_CR2 ;
        volatile U32 SPI_SR  ;
        volatile U32 SPI_DR  ;
};

struct spi1 * SPI1 = SPI1_BASE;



#endif /* SPI_PRIVATE_H_ */
