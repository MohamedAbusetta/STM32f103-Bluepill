#ifndef _MACROS_
#define _MACROS_

//Macros
#define _SETBIT(PORT,PIN)    (PORT|=(U32)(1<<PIN))
#define _CLRBIT(PORT,PIN)    (PORT&=~(U32)(1<<PIN))
#define _TOGGLEBIT(PORT,PIN) (PORT^=(U32)(1<<PIN))
#define _GETBIT(PORT,PIN)    ((PORT>>PIN)&(U32)1)

#endif