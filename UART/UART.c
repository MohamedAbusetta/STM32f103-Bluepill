#include "../Vertical Layer/Datatypes.h"

#include "UART_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"
#include "../GPIO/GPIO_interface.h"
#include "../RCC/RCC_interface.h"

#include "UART_cfg.h"
#include "UART_private.h"

extern void UART1_voidInit (void)
{
  //Enable clk
  RCC_voidEnableGPIO(PORTA);  //Port A
  RCC_voidEnableUART(UART_1); //Uart and alternative function
  
  GPIO_voidSetPinDirection(PORTA,PIN10,INPUT,IN_PULLUD); //RX input pull up
  GPIO_voidSetPullUp(PORTA,PIN10);
  GPIO_voidSetPinDirection(PORTA,PIN9,OUT_50MHZ,OUT_AF_PUSH_PULL); //TX output push pull
  
  //enable uart
   _SETBIT(UART1->CR1,13);
    
  //set word as 8bit
   _CLRBIT(UART1->CR1,12);
    
  //buadrate 9600
  UART1->BRR =0x341;// 0x341;//
  
  //enable TX and RX
  _SETBIT(UART1->CR1,3);
  _SETBIT(UART1->CR1,2);
  
  //enable interrupt 
  //_SETBIT(USART1->CR1,6);
  
  //clear status reg manually
  UART1->SR = 0x0000;
    
}

extern void UART1_voidSend (U8 Data)
{
  
  UART1->DR = Data;  
  //while(!_GETBIT(UART1->SR,6));
  //_CLRBIT(UART1->SR,7);
  //_CLRBIT(UART1->SR,6);
}

extern U8 UART1_U8Recive (void)
{
  U8 RetVal = 0;
  RetVal = UART1->DR;
  while(!_GETBIT(UART1->SR,5));
  //_CLRBIT(UART1->SR,7);
  _CLRBIT(UART1->SR,5);
  
  return RetVal;
}

