#include "../Vertical Layer/Datatypes.h"
#include "../Vertical Layer/Macros.h"
#include "RTOS_interface.h"
#include "../GPIO/GPIO_interface.h"
#include "../NVIC/NVIC_interface.h"
#include "../RCC/RCC_interface.h"
#include "PWM_interface.h"


void main( void )
{
  RCC_voidInitSysClock();
  RCC_voidEnableGPIO(PORTC_RCC);
  GPIO_voidSetPinDirection(PORTC,PIN13,OUT_50MHZ,OUT_GP_PUSH_PULL);
  GPIO_voidSetPinValue(PORTC,PIN13,HIGH);
  
  PWM2_voidInit();
  PWM2_voidSetDutyCycle(20);
  PWM2_voidSetFrequancy(16);

  
  
    
  while(1)
  {
    
  }

}
