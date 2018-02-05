#include "../Vertical Layer/Datatypes.h"
#include "../Vertical Layer/Macros.h"
#include "RTOS_interface.h"
#include "../GPIO/GPIO_interface.h"
#include "../RCC/RCC_interface.h"

void LED_runable(void);

void LED_runable(void)
{
  GPIO_voidSetPinValue(PORTC,PIN13,TOGGLE);
}


void main( void )
{
  
  
   RCC_voidInitSysClock();
   RCC_voidEnableGPIO(PORTC);
   GPIO_voidSetPinDirection(PORTC,PIN13,OUT_10MHZ,OUT_GP_PUSH_PULL);
   GPIO_voidSetPinValue(PORTC,PIN13,LOW);
   RTOS_voidInit();
   RTOS_Task LED = {500,0,LED_runable,0};
   RTOS_voidCreateTask(&LED);
   RTOS_voidStart();
}
