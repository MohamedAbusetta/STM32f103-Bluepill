#ifndef _RCC_INTERFACE_
#define _RCC_INTERFACE_

/* #DEFINES# */


/* #VARIBLES# */
enum PORTS{PORTA,PORTB,PORTC,PORTD,PORTE,PORTF,PORTG};
enum USART{UART_1,UART_2,UART_3};

/* #FUNCTION_PROTOTYPES# */
extern void RCC_voidInitSysClock (void);

/*
 INPUT (Gpio) >> is one input from enum PORTS{}
*/
extern void RCC_voidEnableGPIO(U8 Gpio);
extern void RCC_voidDisableGPIO(U8 Gpio);

/*
 INPUT (Usart) >> is one input from enum USART{}
*/
extern void RCC_voidEnableUSART (U8 Usart);
extern void RCC_voidDisableUSART (U8 Usart);

extern void RCC_voidEnableMCO (void);
#endif