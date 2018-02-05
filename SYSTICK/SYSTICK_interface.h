#ifndef _SYSTEMCLOCK_INTERFACE_
#define _SYSTEMCLOCK_INTERFACE_

/* #DEFINES# */


/* #VARIBLES# */


/* #FUNCTION_PROTOTYPES# */
extern void SYSTICK_voidInit (void);
extern U32 SYSTICK_U32GetVal (void);
extern void SYSTICK_voidSetHandler (void (* Ptr) (void));


#endif