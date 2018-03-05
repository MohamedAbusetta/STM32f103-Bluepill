#include "../Vertical layer/Datatypes.h"

#include "../GPIO/GPIO_interface.h"
#include "../RCC/RCC_interface.h"

//Vertical Layer libs
#include "../Vertical layer/Macros.h"
#include "ICU_cfg.h" 
#include "ICU_interface.h"
#include "ICU_private.h"



extern void IPCAPTURE3_voidInit(void)
{ 
  //Enable RCC  TIM2 & alternative
  RCC_voidEnableTIM3();
  RCC_voidEnableGPIO(PORTA_RCC);
  
  //GPIO Port A pin 6,7
  GPIO_voidSetPinDirection(PORTA,PIN6,INPUT,IN_FLOAT);
  GPIO_voidSetPinDirection(PORTA,PIN7,INPUT,IN_FLOAT);
  
  //select CH1 and CH2 as input
  _SETBIT(TIM3->TIM3_CCMR1,_INPUT_CH1_T1);
  _SETBIT(TIM3->TIM3_CCMR1,_INPUT_CH2_T1);
  
  //set timer freq PRESCALER
   TIM3->TIM3_PSC = _TIMER3_PRESCALE8; // 1Mhz sysclock/(psc+1)

  //select polarity (CH1 &CH2 OPPOSITE)
   _SETBIT(TIM3->TIM3_CCER,_CC2_POLARITY);//falling edge CH2...rising edge CH1

  //SELECT T1FP1 AS TRIGGER I/P
   TIM3->TIM3_SMCR|=_TRIGGER_INPUT1;
  //SLAVE MODE IN RESET
   TIM3->TIM3_SMCR|=_SMS_RESET_MODE;
//NO PRESCALR ONCAPTURE,IC1PSC,IC2PSC=00
   //Capture enable
   _SETBIT(TIM3->TIM3_CCER,_CAPTURE_ENABLE_CH1);
   _SETBIT(TIM3->TIM3_CCER,_CAPTURE_ENABLE_CH2);

  //enable interrupt
#if _PWM2_ENABLE_INTERRUPT == TRUE
  _SETBIT(TIM3->TIM3_DIER,_CAPTURE1_INTERRUPT_ENABLE);
  _SETBIT(TIM3->TIM3_DIER,_CAPTURE2_INTERRUPT_ENABLE);
#endif
  
    //counter enable
  _SETBIT(TIM3->TIM3_CR1,_TIMER3_ENABLE );

}

extern void IP_CAP_Task(void){
       if(_GETBIT(TIM3->TIM3_SR,_CAPTURE2_INT_FLAG))
       { //PULSE WIDTH
             PW=TIM3->TIM3_CCR2;
       }
	if(_GETBIT(TIM3->TIM3_SR,_CAPTURE1_INT_FLAG)){ //PERIOD
	       PERIOD=TIM3->TIM3_CCR1;
	       freq=_TIMER3_FREQ_HZ/PERIOD;
	       DC= ((PW*100)/PERIOD)+1;
	       DC_FLAG=1;
	       FREQ_FLAG=1;
		}
}

extern U8   IPCAPTURE3_voidGetDutyCycle(void){
//	if(DC_FLAG==1)
//        {
//          DC_FLAG=0;
          return DC;
//	}

}
extern U16  IPCAPTURE3_voidGetFrequancy(void){
//	if(FREQ_FLAG==1)
//        {
//            FREQ_FLAG=0;
            return freq;
//	}
}