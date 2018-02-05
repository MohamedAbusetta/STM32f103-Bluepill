#ifndef _NVIC_PRIVATE
#define _NVIC_PRIVATE

/* #DEFINES# */
#define NVIC_BASE (struct nvic *)0xE000E100

/* #VARIBLES# */

struct nvic
{
  volatile U32 ISER[2]; //volatile U32 ISERl; 
  volatile U32 ICER[2]; //volatile U32 ISERl1;
  volatile U32 ISPR[2]; //volatile U32 ISERl3;
  volatile U32 ICPR[2];
};

static struct nvic * NVIC = NVIC_BASE ;


/* #FUNCTION_PROTOTYPES# */

#endif