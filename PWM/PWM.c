#include "../Vertical Layer/Datatypes.h"

#include "PWM_interface.h"
#include "../GPIO/GPIO_interface.h"
#include "../RCC/RCC_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"
#include "PWM_private.h"
#include "PWM_cfg.h"



extern void PWM2_voidInit(void)
{ 
  //Enable RCC  TIM2 & alternative
  RCC_voidEnableTIM2();
  RCC_voidEnableGPIO(PORTA_RCC);
  
  //GPIO Port A pin 0 out AF push pull
  GPIO_voidSetPinDirection(PORTA,PIN1,OUT_50MHZ,OUT_AF_PUSH_PULL);
  
  //set timer freq PRESCALER 
  TIM2->TIM2_PSC = _PWM2_PRESCALE8; // 1Mhz sysclock/(psc+1)
  
  //set PWM Freq
  freq = 1000000/_PWM2_FREQ_HZ;
  TIM2->TIM2_ARR  = freq;
  
  //set DC
  DC = (freq*_PWM_DC)/100;
  TIM2->TIM2_CCR2 = DC;
  
  //set the mode to mode1
  TIM2->TIM2_CCMR1 = (_MODE1<<_PWM2_MODE_SHIFT);
  
  //enable preload
  _SETBIT(TIM2->TIM2_CCMR1,_PWM2_OC2PE );
  
  //enable auto reload
  _SETBIT(TIM2->TIM2_CR1,_PWM2_ARPE);
  
  //Enable OC2
  _SETBIT(TIM2->TIM2_CCER,_PWM2_CC2E);

  //enable interrupt
#if _PWM2_ENABLE_INTERRUPT == TRUE
  _SETBIT(TIM2->TIM2_DIER,_PWM2_INTERRUPT_ENABLE);
#endif
  
    //counter enable
  _SETBIT(TIM2->TIM2_CR1,_PWM2_ENABLE_PWM2);

}

extern void PWM2_voidSetDutyCycle(U8 DutyCycle)
{
  //set DC
  DC = (freq*DutyCycle)/100;
  TIM2->TIM2_CCR2 =DC;
}

extern void PWM2_voidSetFrequancy(U16 Frequancy)
{
  freq = 1000000/Frequancy;
  TIM2->TIM2_ARR  = freq;
  
  //set DC
  DC = (freq*DC)/100;
  TIM2->TIM2_CCR2 =DC;
}