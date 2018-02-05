#ifndef _GPIO_PRIVATE_
#define _GPIO_PRIVATE_

/* #DEFINES# */

#define GPIOA_BASE	(struct gpio *)  0x40010800
#define GPIOB_BASE	(struct gpio *)  0x40010C00
#define GPIOC_BASE	(struct gpio *)  0x40011000

//Modes
#define _MOD_OUTPUT_10MHZ 0x1
#define _MOD_OUTPUT_2MHZ  0x2
#define _MOD_OUTPUT_50MHZ 0x3
#define _MOD_INPUT        0x0

//OUTPUT CFG
#define _CFG_OUTPUT_GP_PUSHPULL   0x0 
#define _CFG_OUTPUT_GP_OPENDRAIN  0x1
#define _CFG_OUTPUT_AF_PUSHPULL   0x2
#define _CFG_OUTPUT_AF_OPENDRAIN  0x3

//OUTPUT CFG
#define _CFG_INPUT_ANALOG   0x0
#define _CFG_INPUT_FLOAT    0x1
#define _CFG_INPUT_PULL_UD  0x2

#define _MODJUMP    4
#define _OUTPUTMOD  0x6
#define _INPUTMOD   0x4
#define _FIRSTREG   8
#define _CLR4BITS   0xF
#define _PULLRISMOD 0X8



/* #VARIBLES# */

enum PORTS{PORTA,PORTB,PORTC,PORTD,PORTE,PORTF,PORTG};

struct gpio 
{
	volatile U32 cr[2];
	volatile U32 idr;
	volatile U32 odr;
	volatile U32 bsrr;
	volatile U32 brr;
	volatile U32 lock;
};

static struct gpio *PortBase[3]={
				   GPIOA_BASE ,
				   GPIOB_BASE ,
				   GPIOC_BASE 
                                 };


/* #FUNCTION_PROTOTYPES# */

#endif