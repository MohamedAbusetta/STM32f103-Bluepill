#ifndef _NVIC_INTERFACE_
#define _NVIC_INTERFACE_

/* #DEFINES# */
#define WWDG 	             0
#define PVD      	     1
#define TAMPER   	     2
#define RTC      	     3
#define FLASH    	     4
#define RCC      	     5
#define EXTI0    	     6
#define EXTI1    	     7
#define EXTI2    	     8
#define EXTI3   	     9	
#define EXTI4   	     10
#define DMA1_Channel1        11
#define DMA1_Channel2        12
#define DMA1_Channel3        13
#define DMA1_Channel4        14
#define DMA1_Channel5        15
#define DMA1_Channel6        16
#define DMA1_Channel7        17
#define ADC1_2   	     18
#define USB_HP_CAN1_TX       19
#define USB_LP_CAN1_RX0      20
#define CAN1_RX1             21
#define CAN1_SCE             22
#define EXTI9_5              23
#define TIM1_BRK             24
#define TIM1_UP              25
#define TIM1_TRG_COM         26
#define TIM1_CC              27
#define TIM2                 28
#define TIM3                 29
#define TIM4                 30
#define I2C1_EV              31
#define I2C1_ER              32
#define I2C2_EV              33
#define I2C2_ER              34
#define SPI1                 35
#define SPI2                 36
#define USART1               37
#define USART2               38
#define USART3               39
#define EXTI15_10            40
#define RTCAlarm             41
#define USBWakeUp            42

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