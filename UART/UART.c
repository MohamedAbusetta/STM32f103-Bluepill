#include "../Vertical Layer/Datatypes.h"

#include "UART_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"
#include "../GPIO/GPIO_interface.h"
#include "../RCC/RCC_interface.h"
#include "../NVIC/NVIC_interface.h"

#include "UART_cfg.h"
#include "UART_private.h"

extern void UART1_voidInit (void)
{
  //Enable clk
  RCC_voidEnableGPIO(PORTA_RCC);  //Port A
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
  _SETBIT(UART1->CR1,6); // 6 when TC "Transmit complete"
  //_SETBIT(UART1->CR1,5); // 5 when RENE "data ready to be read"
  
  NVIC_voidEnableInterruptX (_USART1 );
  
  //clear status reg manually
  UART1->SR = 0x0000;
    
}

extern void UART1_voidSend (U8 Data)
{
  
  UART1->DR = Data;  
  while(!_GETBIT(UART1->SR,6));
  _CLRBIT(UART1->SR,6);
}

extern U8 UART1_U8Recive (void)
{
  U8 RetVal = 0;
  RetVal = UART1->DR;
  while(!_GETBIT(UART1->SR,5));
  _CLRBIT(UART1->SR,5);
  
  return RetVal;
}

extern U8 UART1_U8SendBuffer (U8 * Buffer , U16 Size)
{

  if(Status == 0)
  {  
    Status = 1; //Update Status == 1 Busy
    GBuffer = Buffer;
    Remain_Bytes = Size ;
    Index_Byte   = 0; 
    
    UART1->DR = GBuffer[0]; //send first byte
  }
  return Status;
}

void USART1_IRQHandler(void)
{
  //Clear interrupt send flag 
  _CLRBIT(UART1->SR,6);
  _CLRBIT(UART1->SR,5);
  _CLRBIT(UART1->SR,7);
  
  //Update Remaining bytes
  Remain_Bytes-- ;
  Index_Byte++; 
  
  //check Remaining bytes 
  if(Remain_Bytes > 0)
  {
    UART1->DR = GBuffer[Index_Byte]; //send rest bytes
  }
  else
  {
    Status = 0; //Transmission complete Update Status == 0 Not Busy
    //USART1_NotBusy();
  }
  
}
