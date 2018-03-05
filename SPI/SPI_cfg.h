/*
 * SPI_CONFG.h
 *
 *  Created on: Feb 17, 2018
 *      Author: sphinx
 */

#ifndef SPI_CONFG_H_
#define SPI_CONFG_H_

#ifndef F_CPU
#define  F_CPU 8000000
#endif

//SPI_1 PORT
#define  SPI1_PORT PORTA
#define  MOSI       PIN7
#define  MISO       PIN6
#define  SS         PIN4
#define  CLK        PIN5

//SPI_1_PRESCALAR
#define  SPI_PRE2   0
#define  SPI_PRE4   1
#define  SPI_PRE8   2
#define  SPI_PRE16  3
#define  SPI_PRE32  4
#define  SPI_PRE64  5
#define  SPI_PRE128 6
#define  SPI_PRE256 7

//SPI_1_BAUDRATE_SELECTED
#define BAUDRATE  SPI_PRE8



#endif /* SPI_CONFG_H_ */
