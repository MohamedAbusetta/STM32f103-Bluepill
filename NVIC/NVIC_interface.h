#ifndef _NVIC_INTERFACE_
#define _NVIC_INTERFACE_

/* #DEFINES# */
#define _WWDG 	             0
#define _PVD      	     1
#define _TAMPER   	     2
#define _RTC      	     3
#define _FLASH    	     4
#define _RCC      	     5
#define _EXTI0    	     6
#define _EXTI1    	     7
#define _EXTI2    	     8
#define _EXTI3   	     9	
#define _EXTI4   	     10
#define _DMA1_Channel1        11
#define _DMA1_Channel2        12
#define _DMA1_Channel3        13
#define _DMA1_Channel4        14
#define _DMA1_Channel5        15
#define _DMA1_Channel6        16
#define _DMA1_Channel7        17
#define _ADC1_2   	     18
#define _USB_HP_CAN1_TX       19
#define _USB_LP_CAN1_RX0      20
#define _CAN1_RX1             21
#define _CAN1_SCE             22
#define _EXTI9_5              23
#define _TIM1_BRK             24
#define _TIM1_UP              25
#define _TIM1_TRG_COM         26
#define _TIM1_CC              27
#define _TIM2                 28
#define _TIM3                 29
#define _TIM4                 30
#define _I2C1_EV              31
#define _I2C1_ER              32
#define _I2C2_EV              33
#define _I2C2_ER              34
#define _SPI1                 35
#define _SPI2                 36
#define _USART1               37
#define _USART2               38
#define _USART3               39
#define _EXTI15_10            40
#define _RTCAlarm             41
#define _USBWakeUp            42

/* #VARIBLES# */


/* #FUNCTION_PROTOTYPES# */
extern void NVIC_voidEnableGlobalInterrupt  (void);
extern void NVIC_voidDisableGlobalInterrupt (void);

/*
INPUT(Interrupt_Index) >> select from defines above
*/
extern void NVIC_voidEnableInterruptX (U8 Interrupt_Index);
extern void NVIC_voidDisableInterruptX (U8 Interrupt_Index);
extern void NVIC_voidDisablePendingtX (U8 Interrupt_Index);

#endif