#ifndef _RCC_PRIVATE_
#define _RCC_PRIVATE_

/* #DEFINES# */

#define _RCC_BASE	(struct rcc *)   0x40021000
//CR
#define _HSION  0
#define _HSIRDY 1
#define _HSEON  16
#define _HSERDY 17
#define _PLLON  24
#define _PLLRDY 25
//CFGR  
#define _PLLXTPRE 17
#define _PLLSRC   16
//APB2  
#define _AFIO 0
#define _IOPA 2
#define _IOPB 3        
#define _IOPC 4        
#define _IOPD 5        
#define _IOPE 6
#define _IOPF 7
#define _IOPG 8
#define _USART1EN 14    
//APB1  
#define _USART2EN 17   
#define _USART3EN 18


/* #VARIBLES# */

//The reset and clock control module 
struct rcc 
{
	volatile U32 CR;	/* 0 - clock control */
	volatile U32 CFGR;	/* 4 - clock config */
	volatile U32 CIR;	/* 8 - clock interrupt */
	volatile U32 APB2ENR;	/* c - peripheral reset */
	volatile U32 APB1ENR;	/* 10 - peripheral reset */
	volatile U32 APB3ENR;	/* 14 - peripheral enable */
	volatile U32 APE2ENR;	/* 18 - peripheral enable */
	volatile U32 APE1ENR;	/* 1c - peripheral enable */
	volatile U32 BDCR;	/* 20 - xx */
	volatile U32 CSR;	/* 24 - xx */
};

//pointer to access rcc registers
static struct rcc * RCC = _RCC_BASE;


/* #FUNCTION_PROTOTYPES# */

static void RCC_voidEnableAlternative  (void);

/*
 INPUT (Gpio) >> is one input from enum PORTS_RCC{}
*/
static void RCC_voidEnableGPIO(U8 Gpio);


/*
 INPUT (Usart) >> is one input from enum USART{}
*/
static void RCC_voidEnableUART (U8 Usart);


static void RCC_voidEnableTIM2 (void);
static void RCC_voidEnableTIM3 (void);

static void RCC_voidEnableMCO (void);

static void RCC_voidEnableSPI1 (void);


#endif