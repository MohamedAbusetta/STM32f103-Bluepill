#ifndef _PWM_PRIVATE_
#define _PWM_PRIVATE_

/* #DEFINES# */

#define _TIM2_BASE	(struct tim2 *)   0x40000000

#define _MODE1                 0x6
#define _PWM2_MODE_SHIFT       12
#define _PWM2_PRESCALE8        7
#define _PWM2_ARPE             7
#define _PWM2_OC2PE            11
#define _PWM2_CC2E             4
#define _PWM2_INTERRUPT_ENABLE 2
#define _PWM2_ENABLE_PWM2      0

/* #VARIBLES# */

struct tim2 
{
	volatile U32 TIM2_CR1   ; 
	volatile U32 TIM2_CR2   ; 
	volatile U32 TIM2_SMCR  ; 
	volatile U32 TIM2_DIER  ; 
	volatile U32 TIM2_SR    ;
	volatile U32 TIM2_EGR   ;
	volatile U32 TIM2_CCMR1 ;
	volatile U32 TIM2_CCMR2 ;
	volatile U32 TIM2_CCER  ;
	volatile U32 TIM2_CNT   ;
        volatile U32 TIM2_PSC   ;
        volatile U32 TIM2_ARR   ;
        volatile U32 RESERVED1  ;
        volatile U32 TIM2_CCR1  ;
        volatile U32 TIM2_CCR2  ;
        volatile U32 TIM2_CCR3  ;
        volatile U32 TIM2_CCR4  ;
        volatile U32 RESERVED2  ;
        volatile U32 TIM2_DCR   ;
        volatile U32 TIM2_DMAR  ;
};

static struct tim2 * TIM2 = _TIM2_BASE;

static U16 freq;
static U16  DC;

/* #FUNCTION_PROTOTYPES# */

#endif