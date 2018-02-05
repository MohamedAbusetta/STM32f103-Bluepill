#ifndef _SYSTEMCLOCK_INTERFACE_
#define _SYSTEMCLOCK_INTERFACE_

/* #DEFINES# */


/* #VARIBLES# */
typedef void (*Ptrtask)(void);

typedef struct 
{
  U16 Periodicity;
  U16 Offset;
  Ptrtask Task_handler;
  U8 Periorty;
}RTOS_Task;

/* #FUNCTION_PROTOTYPES# */
extern void RTOS_voidInit (void);
extern void RTOS_voidCreateTask(RTOS_Task* Task);
extern void RTOS_voidStart (void);




#endif