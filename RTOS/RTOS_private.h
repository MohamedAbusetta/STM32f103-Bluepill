#ifndef _SYSTEMCLOCK_PRIVATE_
#define _SYSTEMCLOCK_PRIVATE_

/* #DEFINES# */
#define NULL_TASK (RTOS_Task*)0

/* #VARIBLES# */
static U8 Task_Number = 0; 
static U8 OS_Flag = 0;
static RTOS_Task* Sys_Tasks[MAX_TASK];

/* #FUNCTION_PROTOTYPES# */
static void RTOS_voidEnable (void);
static void RTOS_voidSchedular (void);

#endif