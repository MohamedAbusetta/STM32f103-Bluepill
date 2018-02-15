#ifndef _RCC_INTERFACE_
#define _RCC_INTERFACE_

/* #DEFINES# */


/* #VARIBLES# */
enum PORTS_RCC{PORTA_RCC,PORTB_RCC,PORTC_RCC,PORTD_RCC,PORTE_RCC,PORTF_RCC,PORTG_RCC};
enum USART{UART_1,UART_2,UART_3};

/* #FUNCTION_PROTOTYPES# */
extern void RCC_voidInitSysClock (void);

/*
 INPUT (Gpio) >> is one input from enum PORTS_RCC{}
*/
extern void RCC_voidEnableGPIO(U8 Gpio);
extern void RCC_voidDisableGPIO(U8 Gpio);

/*
 INPUT (Usart) >> is one input from enum USART{}
*/
extern void RCC_voidEnableUART (U8 Usart);
extern void RCC_voidDisableUART (U8 Usart);

extern void RCC_voidEnableTIM2 (void);

extern void RCC_voidEnableMCO (void);

#endif