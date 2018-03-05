#include "../Vertical layer/Datatypes.h"
#include "SPI_interface.h"


#include "../GPIO/GPIO_interface.h"

#include "../Vertical layer/Macros.h"
#include "SPI_private.h"
#include "SPI_cfg.h"


 extern void SPI_INITMaster(void)
{
  //pin confg
  //SCK
  GPIO_voidSetPinDirection(PORTA,CLK,OUT_50MHZ,OUT_AF_PUSH_PULL);
  //MOSI
  GPIO_voidSetPinDirection(PORTA,MOSI,OUT_50MHZ,OUT_AF_PUSH_PULL);
  //MISO
  GPIO_voidSetPinDirection(PORTA,MISO,INPUT,IN_PULLUD);
  GPIO_voidSetPullUp(PORTA,MISO);
  
  //baudrate
  SPI1->SPI_CR1 = (BAUDRATE<<BR);
  //CPOL CPHA
  
  //8bits
  
  //MSB
  
  //SET 
  _SETBIT(SPI1->SPI_CR1,SSM);
  _SETBIT(SPI1->SPI_CR1,SSI);

  //ENABLE
  _SETBIT(SPI1->SPI_CR1,MSTR);
  _SETBIT(SPI1->SPI_CR1,SPE);
}

 extern void SPI_INITSlave(void)
{
  //pin confg
  GPIO_voidSetPinDirection(PORTA,CLK,INPUT,IN_FLOAT);  //SCK
  GPIO_voidSetPinDirection(PORTA,MOSI,INPUT,IN_PULLUD); //MOSI
  GPIO_voidSetPullUp(PORTA,MOSI);//Pull up MOSI
  GPIO_voidSetPinDirection(PORTA,MISO,OUT_50MHZ,OUT_AF_PUSH_PULL);  //MISO
 
  //baudrate
  SPI1->SPI_CR1 = (BAUDRATE<<BR);
  //CPOL CPHA
  
  //8bits
  
  //MSB
  
  //SET 
  _SETBIT(SPI1->SPI_CR1,SSM);
  _CLRBIT(SPI1->SPI_CR1,SSI);

  //ENABLE
  _CLRBIT(SPI1->SPI_CR1,MSTR);
  _SETBIT(SPI1->SPI_CR1,SPE);
  
}
extern void  SPI_SEND(U8 Data)
{
    SPI1->SPI_DR=Data;        
    while(!_GETBIT(SPI1->SPI_SR,TXE));
}
 extern U8  SPI_RECIVE(void)
{
  U8 RetVal = 0;
  while(!_GETBIT(SPI1->SPI_SR,RXNE));
    RetVal=SPI1->SPI_DR;
    SPI1->SPI_DR= RetVal;
    return RetVal;
}

extern U8  SPI_SENDRECIVE(U8 Data)
{
	while(!(_GETBIT(SPI1->SPI_SR,TXE)));
	SPI1->SPI_DR=Data;
	while(!(_GETBIT(SPI1->SPI_SR,RXNE)));
	return SPI1->SPI_DR;
}
