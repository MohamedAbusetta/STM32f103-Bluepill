#ifndef _NVIC_INTERFACE_
#define _NVIC_INTERFACE_

/* #DEFINES# */
#define NMI                  0
#define HardFault            1
#define MemManage            2
#define BusFault             3
#define UsageFault           4
#define SVC                  5
#define DebugMon             6
#define PendSV               7
#define SysTick              8
#define WWDG 	             9	
#define PVD      	     10
#define TAMPER   	     11
#define RTC      	     12
#define FLASH    	     13
#define RCC      	     14
#define EXTI0    	     15
#define EXTI1    	     16
#define EXTI2    	     17
#define EXTI3   	     18
#define EXTI4   	     19
#define DMA1_Channel1        20
#define DMA1_Channel2        21
#define DMA1_Channel3        22
#define DMA1_Channel4        23
#define DMA1_Channel5        24
#define DMA1_Channel6        25
#define DMA1_Channel7        26
#define ADC1_2   	     27
#define USB_HP_CAN1_TX       28
#define USB_LP_CAN1_RX0      29
#define CAN1_RX1             30
#define CAN1_SCE             31
#define EXTI9_5              32
#define TIM1_BRK             33
#define TIM1_UP              34
#define TIM1_TRG_COM         35
#define TIM1_CC              36
#define TIM2                 37
#define TIM3                 38
#define TIM4                 39
#define I2C1_EV              40
#define I2C1_ER              41
#define I2C2_EV              42
#define I2C2_ER              43
#define SPI1                 44
#define SPI2                 45
#define USART1               46
#define USART2               47
#define USART3               48
#define EXTI15_10            49
#define RTCAlarm             50
#define USBWakeUp            51

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