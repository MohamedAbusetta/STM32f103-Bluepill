/**************************************************
 *
 * This file contains an interrupt vector for Cortex-M written in C.
 * The actual interrupt functions must be provided by the application developer.
 *
 * Copyright 2007 IAR Systems. All rights reserved.
 *
 * $Revision: 66254 $
 *
 **************************************************/

// The vector table is normally located at address 0.
// When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
// If you need to define interrupt service routines,
// make a copy of this file and include it in your project.
// The name "__vector_table" has special meaning for C-SPY, which
// is where to find the SP start value.
// If vector table is not located at address 0, the user has to initialize
// the  NVIC vector table register (VTOR) before using interrupts.


#pragma language=extended
#pragma segment="CSTACK"

extern void __iar_program_start( void );


 extern void NMI_Handler                    ( void ) ;
 extern void HardFault_Handler              ( void ) ;
 extern void MemManage_Handler              ( void ) ;
 extern void BusFault_Handler               ( void ) ;
 extern void UsageFault_Handler             ( void ) ;
 extern void SVC_Handler                    ( void ) ;
 extern void DebugMon_Handler               ( void ) ;                  
 extern void PendSV_Handler                 ( void ) ;
 extern void SysTick_Handler                ( void ) ;
 extern void WWDG_IRQHandler    	     ( void ) ;
 extern void PVD_IRQHandler     	     ( void ) ;
 extern void TAMPER_IRQHandler  	     ( void ) ;
 extern void RTC_IRQHandler     	     ( void ) ;
 extern void FLASH_IRQHandler   	     ( void ) ;
 extern void RCC_IRQHandler     	     ( void ) ;
 extern void EXTI0_IRQHandler   	     ( void ) ;
 extern void EXTI1_IRQHandler   	     ( void ) ;
 extern void EXTI2_IRQHandler   	     ( void ) ;
 extern void EXTI3_IRQHandler  	     ( void ) ;
 extern void EXTI4_IRQHandler  	     ( void ) ;
 extern void DMA1_Channel1_IRQHandler       ( void ) ;
 extern void DMA1_Channel2_IRQHandler       ( void ) ;
 extern void DMA1_Channel3_IRQHandler       ( void ) ;
 extern void DMA1_Channel4_IRQHandler       ( void ) ;
 extern void DMA1_Channel5_IRQHandler       ( void ) ;
 extern void DMA1_Channel6_IRQHandler       ( void ) ;
 extern void DMA1_Channel7_IRQHandler       ( void ) ;
 extern void ADC1_2_IRQHandler  	     ( void ) ;
 extern void USB_HP_CAN1_TX_IRQHandler      ( void ) ;
 extern void USB_LP_CAN1_RX0_IRQHandler     ( void ) ;
 extern void CAN1_RX1_IRQHandler            ( void ) ;
 extern void CAN1_SCE_IRQHandler            ( void ) ;
 extern void EXTI9_5_IRQHandler             ( void ) ;
 extern void TIM1_BRK_IRQHandler            ( void ) ;
 extern void TIM1_UP_IRQHandler             ( void ) ;
 extern void TIM1_TRG_COM_IRQHandler        ( void ) ;
 extern void TIM1_CC_IRQHandler             ( void ) ;
 extern void TIM2_IRQHandler                ( void ) ;
 extern void TIM3_IRQHandler                ( void ) ;
 extern void TIM4_IRQHandler                ( void ) ;
 extern void I2C1_EV_IRQHandler             ( void ) ;
 extern void I2C1_ER_IRQHandler             ( void ) ;
 extern void I2C2_EV_IRQHandler             ( void ) ;
 extern void I2C2_ER_IRQHandler             ( void ) ;
 extern void SPI1_IRQHandler                ( void ) ;
 extern void SPI2_IRQHandler                ( void ) ;
 extern void USART1_IRQHandler              ( void ) ;
 extern void USART2_IRQHandler              ( void ) ;
 extern void USART3_IRQHandler              ( void ) ;
 extern void EXTI15_10_IRQHandler           ( void ) ;
 extern void RTCAlarm_IRQHandler            ( void ) ;
 extern void USBWakeUp_IRQHandler           ( void ) ;

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;


#pragma location = ".intvec"
const intvec_elem __vector_table[] =
{
  /*System interrupts*/
      { .__ptr = __sfe( "CSTACK" ) }, //Stack pointer
      __iar_program_start,            //Reset handler      
      NMI_Handler,		      // The NMI handler
      HardFault_Handler,              // The hard fault handler
      MemManage_Handler,              // The MPU fault handler
      BusFault_Handler,               // The bus fault handler
      UsageFault_Handler,             // The usage fault handler
      0,                              // Reserved
      0,                              // Reserved
      0,                              // Reserved
      0,                              // Reserved
      SVC_Handler,                    // SVCall handler
      DebugMon_Handler,               // Debug monitor handler
      0,                              // Reserved
      PendSV_Handler,                 // The PendSV handler
      SysTick_Handler,                // The SysTick handler
  /******************/
  /* Chip Level - STM32F103 */
      WWDG_IRQHandler,   		// Window WatchDog
      PVD_IRQHandler,    		// PVD through EXTI Line detection
      TAMPER_IRQHandler, 		// Tamper through the EXTI line
      RTC_IRQHandler,    		// RTC Wakeup through the EXTI line
      FLASH_IRQHandler,  		// FLASH
      RCC_IRQHandler,    		// RCC
      EXTI0_IRQHandler,  		// EXTI Line0
      EXTI1_IRQHandler,  		// EXTI Line1
      EXTI2_IRQHandler,  		// EXTI Line2
      EXTI3_IRQHandler, 		// EXTI Line3
      EXTI4_IRQHandler, 		// EXTI Line4
      DMA1_Channel1_IRQHandler,         // DMA1 Channel 1
      DMA1_Channel2_IRQHandler,         // DMA1 Channel 2
      DMA1_Channel3_IRQHandler,         // DMA1 Channel 3
      DMA1_Channel4_IRQHandler,         // DMA1 Channel 4
      DMA1_Channel5_IRQHandler,         // DMA1 Channel 5
      DMA1_Channel6_IRQHandler,         // DMA1 Channel 6
      DMA1_Channel7_IRQHandler,         // DMA1 Channel 7
      ADC1_2_IRQHandler, 		// ADC1, ADC2
      USB_HP_CAN1_TX_IRQHandler, 
      USB_LP_CAN1_RX0_IRQHandler, 
      CAN1_RX1_IRQHandler,
      CAN1_SCE_IRQHandler,
      EXTI9_5_IRQHandler, 
      TIM1_BRK_IRQHandler,
      TIM1_UP_IRQHandler, 
      TIM1_TRG_COM_IRQHandler, 
      TIM1_CC_IRQHandler, 
      TIM2_IRQHandler, 
      TIM3_IRQHandler, 
      TIM4_IRQHandler, 
      I2C1_EV_IRQHandler, 
      I2C1_ER_IRQHandler, 
      I2C2_EV_IRQHandler, 
      I2C2_ER_IRQHandler, 
      SPI1_IRQHandler, 
      SPI2_IRQHandler, 
      USART1_IRQHandler, 
      USART2_IRQHandler, 
      USART3_IRQHandler, 
      EXTI15_10_IRQHandler,
      RTCAlarm_IRQHandler, 
      USBWakeUp_IRQHandler,
      0, //
      0, //
      0, //
      0, //
      0, //
      0, //
      0
};

#pragma call_graph_root = "interrupt" 
__weak void NMI_Handler 		   ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void HardFault_Handler              ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void MemManage_Handler              ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void BusFault_Handler               ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void UsageFault_Handler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void SVC_Handler                    ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DebugMon_Handler               ( void ) { while (1) {} }                  
#pragma call_graph_root = "interrupt" 
__weak void PendSV_Handler                 ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void SysTick_Handler                ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void WWDG_IRQHandler    	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void PVD_IRQHandler     	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void TAMPER_IRQHandler  	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void RTC_IRQHandler     	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void FLASH_IRQHandler   	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void RCC_IRQHandler     	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void EXTI0_IRQHandler   	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void EXTI1_IRQHandler   	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void EXTI2_IRQHandler   	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void EXTI3_IRQHandler  	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"       
__weak void EXTI4_IRQHandler  	            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DMA1_Channel1_IRQHandler       ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DMA1_Channel2_IRQHandler       ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DMA1_Channel3_IRQHandler       ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DMA1_Channel4_IRQHandler       ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DMA1_Channel5_IRQHandler       ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DMA1_Channel6_IRQHandler       ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void DMA1_Channel7_IRQHandler       ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void ADC1_2_IRQHandler  	           ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void USB_HP_CAN1_TX_IRQHandler      ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void USB_LP_CAN1_RX0_IRQHandler     ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void CAN1_RX1_IRQHandler            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void CAN1_SCE_IRQHandler            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void EXTI9_5_IRQHandler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void TIM1_BRK_IRQHandler            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void TIM1_UP_IRQHandler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void TIM1_TRG_COM_IRQHandler        ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void TIM1_CC_IRQHandler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void TIM2_IRQHandler                ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void TIM3_IRQHandler                ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void TIM4_IRQHandler                ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void I2C1_EV_IRQHandler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void I2C1_ER_IRQHandler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void I2C2_EV_IRQHandler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void I2C2_ER_IRQHandler             ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void SPI1_IRQHandler                ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void SPI2_IRQHandler                ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void USART1_IRQHandler              ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void USART2_IRQHandler              ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void USART3_IRQHandler              ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void EXTI15_10_IRQHandler           ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void RTCAlarm_IRQHandler            ( void ) { while (1) {} }
#pragma call_graph_root = "interrupt" 
__weak void USBWakeUp_IRQHandler           ( void ) { while (1) {} }


void __cmain( void );
__weak void __iar_init_core( void );
__weak void __iar_init_vfp( void );

#pragma required=__vector_table
void __iar_program_start( void )
{
  __iar_init_core();
  __iar_init_vfp();
  __cmain();
}
