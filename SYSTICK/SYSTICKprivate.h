#ifndef _SYSTEMCLOCK_PRIVATE_
#define _SYSTEMCLOCK_PRIVATE_

/* #DEFINES# */

#define SYSCLK_BASE (struct sysclk *)0xE000E010
#define LOAD_VALUE  (SYS_CLOCK*OS_TICK_MS)/(1000)

/* #VARIBLES# */

struct sysclk
{
	volatile U32 CTRL  ;
	volatile U32 LOAD  ;
	volatile U32 VAL   ;
	volatile U32 CALIB ;
};

static struct sysclk * SYSCLK =  SYSCLK_BASE;
static void (* GPtr) (void) ;

/* #FUNCTION_PROTOTYPES# */

//void SysTick_Handler(void);
void Stub (void);


#endif