#include "../Vertical Layer/Datatypes.h"

#include "SYSTICK_interface.h"

#include "../NVIC/NVIC_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"

#include "SYSTICK_cfg.h"
#include "SYSTICK_private.h"



extern void SYSCLK_voidInit (void)
{
  
  //Set Reload reg
    SYSCLK->LOAD = (U32) LOAD_VALUE;
  //AHB CLK
    _SETBIT(SYSCLK->CTRL,2);
  
  //Enable interrupt request
    _SETBIT(SYSCLK->CTRL,1);
  
  //Enable the sysclk 
    _SETBIT(SYSCLK->CTRL,0);
        
  
}

extern U32 SYSCLK_U32GetVal (void)
{
 U32 RetVal = SYSCLK->VAL ; 
 return RetVal;
}


extern void SYSCLK_voidSetHandler (void (* Ptr) (void))
{
  GPtr = Ptr;
}

void SysTick_Handler(void)
{
  GPtr();
}

static void Stub (void)
{
  return ;
}
