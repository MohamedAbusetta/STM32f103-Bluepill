#ifndef _IPCAPTURE_PRIVATE_
#define _IPCAPTURE_PRIVATE_

/* #DEFINES# */

#define _TIM3_BASE	(struct tim3 *)   0x40000400



#define _TIMER3_PRESCALE8          7
#define _CAPTURE1_INTERRUPT_ENABLE 1
#define _CAPTURE2_INTERRUPT_ENABLE 2
#define _TIMER3_ENABLE             0
#define _INPUT_CH1_T1              0
#define _INPUT_CH2_T1              9
#define _CC2_POLARITY              5 //1:FALLING,0:RISING
#define _CC1_POLARITY              1
#define _TRIGGER_INPUT1           (5<<4)
#define _SMS_RESET_MODE            4
#define _CAPTURE_ENABLE_CH1        0
#define _CAPTURE_ENABLE_CH2        4
#define _CAPTURE1_INT_FLAG         1//CC1F
#define _CAPTURE2_INT_FLAG         2//CC2F


/* #VARIBLES# */

struct tim3
{
	    volatile U32 TIM3_CR1   ;
	    volatile U32 TIM3_CR2   ;
	    volatile U32 TIM3_SMCR  ;
	    volatile U32 TIM3_DIER  ;
	    volatile U32 TIM3_SR    ;
	    volatile U32 TIM3_EGR   ;
	    volatile U32 TIM3_CCMR1 ;
	    volatile U32 TIM3_CCMR2 ;
	    volatile U32 TIM3_CCER  ;
	    volatile U32 TIM3_CNT   ;
        volatile U32 TIM3_PSC   ;
        volatile U32 TIM3_ARR   ;
        volatile U32 RESERVED1  ;
        volatile U32 TIM3_CCR1  ;
        volatile U32 TIM3_CCR2  ;
        volatile U32 TIM3_CCR3  ;
        volatile U32 TIM3_CCR4  ;
        volatile U32 RESERVED2  ;
        volatile U32 TIM3_DCR   ;
        volatile U32 TIM3_DMAR  ;
};

static struct tim3 * TIM3 = _TIM3_BASE;

static U16 freq;
static U16 DC;
static U8  DC_FLAG;
static U8  FREQ_FLAG;
static U16 PW;
static U16 PERIOD;



/* #FUNCTION_PROTOTYPES# */

#endif
