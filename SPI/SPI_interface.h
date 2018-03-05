/*
 * SPI_INTERFACE.h
 *
 *  Created on: Feb 17, 2018
 *      Author: sphinx
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


extern void SPI_INITMaster(void);
extern void SPI_INITSlave(void);
extern void  SPI_SEND(U8 Data);
extern U8  SPI_RECIVE(void);
extern U8  SPI_SENDRECIVE(U8 Data);


#endif /* SPI_INTERFACE_H_ */
