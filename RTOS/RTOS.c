#include "../Vertical Layer/Datatypes.h"

#include "RTOS_interface.h"

#include "../SYSTICK/SYSTICK_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"

#include "RTOS_cfg.h"
#include "RTOS_private.h"



extern void RTOS_voidInit (void)
{
  U16 i = 0;
  
   SYSTICK_voidInit();
  //Set call back function
   SYSTICK_voidSetHandler(RTOS_voidEnable);
     
  //set all tasks to null
  for(i = 0 ; i < MAX_TASK ; i++)
  {
    Sys_Tasks[i] = NULL_TASK;
  }
}

static void RTOS_voidEnable (void)
{
  OS_Flag = 1;
}

extern void RTOS_voidCreateTask(RTOS_Task* Task)
{
  Sys_Tasks[Task->Periorty] = Task;
  Task_Number++;
}

static void RTOS_voidSchedular (void)
{
  U16 i = 0;
  
  for(i = 0 ; i < Task_Number ; i++)
  {
    if(Sys_Tasks[i]->Offset == 0)
    {
      Sys_Tasks[i]->Task_handler();
      Sys_Tasks[i]->Offset = Sys_Tasks[i]->Periodicity;
    }
    Sys_Tasks[i]->Offset--;
  }
}


extern void RTOS_voidStart (void)
{
  while(1)
  {
    if(OS_Flag == 1)
    {
      RTOS_voidSchedular();
      OS_Flag = 0;
    }
  }
}
