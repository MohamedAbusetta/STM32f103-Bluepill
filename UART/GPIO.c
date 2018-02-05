#include "../Vertical Layer/Datatypes.h"

#include "GPIO_interface.h"

//Vertical Layer libs
#include "../Vertical Layer/Macros.h"

#include "GPIO_cfg.h"
#include "GPIO_private.h"


extern void GPIO_voidSetPinDirection(U8 Port,U8 Pin,U8 Direction,U8 Confg)
{
    U8 index = 0;
  
  //Check if pin in Control Reg high or low
    if(Pin >= _FIRSTREG) /* if pin > 8 */
    {
      //Select control high Reg
      index = 1;
      //reallocate pin position
      Pin-=_FIRSTREG;
    }
    
    //Clear old congiguration and mode
    PortBase[Port]->cr[index] &=~ ((0xF)<<(Pin*_MODJUMP));  
    
    switch (Direction)
    {
    case OUT_10MHZ:
      PortBase[Port]->cr[index] |= ((_MOD_OUTPUT_10MHZ)<<(Pin*_MODJUMP));    
      break;    
    case OUT_2MHZ:
      PortBase[Port]->cr[index] |= ((_MOD_OUTPUT_2MHZ)<<(Pin*_MODJUMP));     
      break;  
    case OUT_50MHZ:
      PortBase[Port]->cr[index] |= ((_MOD_OUTPUT_50MHZ)<<(Pin*_MODJUMP)); 
      break;
    case INPUT:
      PortBase[Port]->cr[index] |= ((_MOD_INPUT)<<(Pin*_MODJUMP)); 
      break;
    default:
      
      break;
    }
    
    switch(Direction)
    {
    case OUT_10MHZ:   
    case OUT_2MHZ:
    case OUT_50MHZ:
            if(Confg == OUT_GP_PUSH_PULL)
      {PortBase[Port]->cr[index] |= ((_CFG_OUTPUT_GP_PUSHPULL<<2)<<(Pin*_MODJUMP));}
      else if(Confg == OUT_GP_OPEN_DRAIN)
      {PortBase[Port]->cr[index] |= ((_CFG_OUTPUT_GP_OPENDRAIN<<2)<<(Pin*_MODJUMP));}
      else if(Confg == OUT_AF_PUSH_PULL)
      {PortBase[Port]->cr[index] |= ((_CFG_OUTPUT_AF_PUSHPULL<<2)<<(Pin*_MODJUMP));}
      else if(Confg == OUT_GP_PUSH_PULL)
      {PortBase[Port]->cr[index] |= ((_CFG_OUTPUT_AF_OPENDRAIN<<2)<<(Pin*_MODJUMP));}
      break;
    case INPUT:
            if(Confg == IN_ANALOG)
      {PortBase[Port]->cr[index] |= ((_CFG_INPUT_ANALOG<<2)<<(Pin*_MODJUMP));}
      else if(Confg == IN_FLOAT)
      {PortBase[Port]->cr[index] |= ((_CFG_INPUT_FLOAT<<2)<<(Pin*_MODJUMP));}
      else if(Confg == IN_PULLUD)
      {PortBase[Port]->cr[index] |= ((_CFG_INPUT_PULL_UD<<2)<<(Pin*_MODJUMP));} 
      break;
    default:
      
      break;
    }
}

extern void GPIO_voidSetPinValue(U8 Port,U8 Pin,U8 Value)
{
  if(Value == HIGH)
  {
    //set odr reg to one
    _SETBIT(PortBase[Port]->odr,Pin);
  } 
  else if (Value == LOW)
  {
    //clear odr reg to zero
    _CLRBIT(PortBase[Port]->odr,Pin);
  }  
  else if (Value == TOGGLE)
  {
    _TOGGLEBIT(PortBase[Port]->odr,Pin);
  }
}


U8   GPIO_U8GetPinValue(U8 Port,U8 Pin)
{
  U8 RetVal;
  RetVal = _GETBIT(PortBase[Port]->idr,Pin);
  return RetVal;   
}

extern void GPIO_voidSetPullUp  (U8 Port,U8 Pin)
{
    _SETBIT(PortBase[Port]->odr,Pin);
}
extern void GPIO_voidSetPullDown(U8 Port,U8 Pin)
{
    _CLRBIT(PortBase[Port]->odr,Pin);
}

