#ifndef _RCC_INTERFACE_
#define _RCC_INTERFACE_

/* #DEFINES# */


/* #VARIBLES# */
enum PORTS_RCC{PORTA_RCC,PORTB_RCC,PORTC_RCC,PORTD_RCC,PORTE_RCC,PORTF_RCC,PORTG_RCC};
enum USART{UART_1,UART_2,UART_3};

/* #FUNCTION_PROTOTYPES# */
extern void RCC_voidInitSysClock (void);
extern void RCC_voidDisableAlternative (void);
extern void RCC_voidDisableGPIO(U8 Gpio);
extern void RCC_voidDisableUART (U8 Usart);

#endif
