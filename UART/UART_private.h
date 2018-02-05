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


U16 Remain_Bytes ;
U16 Index_Byte   ;
U8 *GBuffer;
U8 Status = 0; // if Status== 0 not Busy

/* #FUNCTION_PROTOTYPES# */
void USART1_IRQHandler(void);

#endif