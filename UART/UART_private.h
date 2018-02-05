#ifndef _UART_PRIVATE_
#define _UART_PRIVATE_

/* #DEFINES# */

#define USART1_BASE	(struct usart *) 0x40013800


/* #VARIBLES# */

struct usart
{
        volatile U32 SR;
        volatile U32 DR;
        volatile U32 BRR;
        volatile U32 CR1;
        volatile U32 CR2;
        volatile U32 CR3;
        volatile U32 GTPR;
};

static struct usart * UART1 = USART1_BASE;

/* #FUNCTION_PROTOTYPES# */

#endif