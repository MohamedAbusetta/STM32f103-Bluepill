#include "../Vertical Layer/Datatypes.h"

#include "RCC_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"

#include "RCC_cfg.h"
#include "RCC_private.h"

extern void RCC_voidInitSysClock (void)
{

_CLRBIT(RCC->CR,_PLLON); //Disable PLL off

#if   HIGH_SPEED_EXTERNAL == TRUE
        
        #if SYS_CLOCK_MHZ == 72
            _CLRBIT(RCC->CFGR,_PLLXTPRE);  //No Div
            RCC->CFGR |= ((7)<<18);     //PLL by 9
        #else
            _SETBIT(RCC->CFGR,_PLLXTPRE);  //Div by 2
            //PLL by ((SYS_CLOCK/4)-1)
            RCC->CFGR |= ((( SYS_CLOCK_MHZ /4)-2)<<18);
            _SETBIT(RCC->CR,_HSEON);       //Enable External clock
            while(!_GETBIT(RCC->CR,_HSERDY));
                
#endif
                               
RCC->CFGR |= 2;            //Enable SW to PLLCLK 
_SETBIT(RCC->CFGR,_PLLSRC); //Enable PLLSRC to HSE
        
  
#elif HIGH_SPEED_INTERNAL == TRUE

        _SETBIT(RCC->CR,_HSION);     //Enable Internal clock
        while(!_GETBIT(RCC->CR,_HSIRDY));
        _SETBIT(RCC->CFGR,_PLLXTPRE);//Div by 2
        //PLL by ((SYS_CLOCK/4)-1)
        RCC->CFGR |= (U32)(((SYS_CLOCK_MHZ/4)-2)<<18);
        _CLRBIT(RCC->CFGR,_PLLSRC);  //Enable PLLSRC to HSI   
        RCC->CFGR |= 2;             //Enable SW to PLLCLK  
  
#endif
        
 _SETBIT(RCC->CR,_PLLON); //Enable PLL on
 while(!_GETBIT(RCC->CR,_PLLRDY));     
}

extern void RCC_voidEnableGPIO(U8 Gpio)
{
  //Enable GPIO clk
    _SETBIT(RCC->APE2ENR,Gpio +2);    
}

extern void RCC_voidDisableGPIO(U8 Gpio)
{
  //Enable GPIO clk
    _CLRBIT(RCC->APB2ENR,Gpio +2);    
}

static void RCC_voidEnableAlternative  (void)
{
    //Enable GPIO clk
    _SETBIT(RCC->APE2ENR,_AFIO);
}

static void RCC_voidDisableAlternative (void)
{
    //Disable GPIO clk
    _CLRBIT(RCC->APB2ENR,_AFIO); 
}

extern void RCC_voidEnableUART (U8 Usart)
{
  //Enable Alternative function clk
  RCC_voidEnableAlternative();
  
  switch (Usart)
  {
  case UART_1 ://Usart1
    //Enable GPIO A clk
    RCC_voidEnableGPIO(PORTA);
    //Enable USART1 clk
    _SETBIT(RCC->APE2ENR,_USART1EN);
    break;
    
  case UART_2 ://Usart2
     //Enable GPIO A clk
    RCC_voidEnableGPIO(PORTA);
    //Enable USART2 clk
    _SETBIT(RCC->APB1ENR,_USART2EN); 
    break;
    
  case UART_3://Usart3
    //Enable GPIO B clk
    RCC_voidEnableGPIO(PORTB);
    //Enable USART3 clk
    _SETBIT(RCC->APB1ENR,_USART3EN);
    break;
    
  default:
    
    break;
  }
  
}

extern void RCC_voidDisableUART (U8 Usart)
{
  
  switch (Usart)
  {
  case UART_1 ://Usart1
    //Disable USART1 clk
    _CLRBIT(RCC->APB2ENR,_USART1EN);
    break;
    
  case UART_2 ://Usart2
    //Disable USART2 clk
    _CLRBIT(RCC->APB1ENR,_USART2EN);    
    break;
    
  case UART_3://Usart3
    //Disable USART3 clk
    _CLRBIT(RCC->APB1ENR,_USART3EN);  
    break;
    
  default:
    
    break;
  }
  
}

extern void RCC_voidEnableMCO (void)
{
  //enable MCO  
    RCC->CFGR |= (4<<24);
}