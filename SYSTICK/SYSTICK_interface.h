#ifndef _SYSTEMCLOCK_INTERFACE_
#define _SYSTEMCLOCK_INTERFACE_

/* #DEFINES# */


/* #VARIBLES# */


/* #FUNCTION_PROTOTYPES# */
extern void SYSCLK_voidInit (void);
extern U32 SYSCLK_U32GetVal (void);
extern void SYSCLK_voidSetHandler (void (* Ptr) (void));


#endif