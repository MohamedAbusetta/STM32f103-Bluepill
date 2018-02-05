#ifndef _UART_INTERFACE_
#define _UART_INTERFACE_

/* #DEFINES# */


/* #VARIBLES# */


/* #FUNCTION_PROTOTYPES# */
extern void UART1_voidInit (void);
extern void UART1_voidSend (U8 Data);
extern U8 UART1_U8Recive (void);
extern U8 UART1_U8SendBuffer (U8 * Buffer , U16 Size);

#endif