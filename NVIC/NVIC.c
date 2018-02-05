#include "../Vertical Layer/Datatypes.h"

#include "NVIC_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"

#include "NVIC_cfg.h"
#include "NVIC_private.h"

extern void NVIC_voidEnableGlobalInterrupt  (void)
{
  //clear to 0 to Enabable
  __asm volatile ("MOV R0,#0");
  __asm volatile ("MSR PRIMASK,R0");
}

extern void NVIC_voidDisableGlobalInterrupt (void)
{
    //Set to 1 o disabable
  __asm volatile ("MOV R0,#1");
  __asm volatile ("MSR PRIMASK,R0");
}

extern void NVIC_voidEnableInterruptX (U8 Interrupt_Index)
{
  //SET corresponding bit in set enable regs
  NVIC->ISER[Interrupt_Index/32] = (1<<(Interrupt_Index%32));
}

extern void NVIC_voidDisableInterruptX (U8 Interrupt_Index)
{
  //SET corresponding bit in clear enable regs
  NVIC->ICER[Interrupt_Index/32] = (1<<(Interrupt_Index%32));;
}

extern void NVIC_voidDisablePendingtX (U8 Interrupt_Index)
{
  //SET corresponding bit in clear enable regs
  NVIC->ICPR[Interrupt_Index/32] = (1<<(Interrupt_Index%32));
}