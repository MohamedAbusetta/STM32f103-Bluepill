#include "../Vertical Layer/Datatypes.h"
#include "GPIO_interface.h"
#include "../RCC/RCC_interface.h"

void delay ()
{
  U64 x = 0;
  while (x<150000){x++;}
}
void main( void )
{ 
    RCC_voidInitSysClock();
    RCC_voidEnableGPIO(PORTC);
    RCC_voidEnableGPIO(PORTB);
    GPIO_voidSetPinDirection(PORTC,PIN13,OUT_2MHZ,OUT_GP_PUSH_PULL);
    GPIO_voidSetPinDirection(PORTB,PIN0,INPUT,IN_PULLUD);
    GPIO_voidSetPullUp(PORTB,PIN0);
    GPIO_voidSetPinValue(PORTC,PIN13,LOW);
    while(1)
    {
      if(GPIO_U8GetPinValue(PORTB,PIN0) == LOW)
      {
        GPIO_voidSetPinValue(PORTC,PIN13,LOW);
      }
      else
      {
        GPIO_voidSetPinValue(PORTC,PIN13,HIGH);
      }
      
      
    }
    
}
