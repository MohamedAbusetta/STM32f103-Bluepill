#ifndef _RCC_CFG_
#define _RCC_CFG_

#define TRUE    1
#define FALSE   0
#define ENABLE  1
#define DISABLE 0

//System clock configuration (ONLY ONE TRUE AT THE SAME TIME)
#define HIGH_SPEED_EXTERNAL TRUE    //(TRUE or FALSE) 
#define HIGH_SPEED_INTERNAL FALSE //(TRUE or FALSE) 

/*Select one of system clock values
>>  8   MHZ
>>  12  MHZ
>>  16  MHZ
>>  20  MHZ
>>  24  MHZ
>>  28  MHZ
>>  32  MHZ
>>  36  MHZ
>>  40  MHZ
>>  44  MHZ
>>  48  MHZ
>>  52  MHZ
>>  56  MHZ
>>  60  MHZ
>>  64  MHZ
>>  68  MHZ  //ONLY AVILABLE in HIGH_SPEED_EXTERNAL
>>  72  MHZ  //ONLY AVILABLE in HIGH_SPEED_EXTERNAL
*/

#define  SYS_CLOCK_MHZ 8


#define _RCC_ENABLE_PORT_A      ENABLE
#define _RCC_ENABLE_PORT_B      ENABLE
#define _RCC_ENABLE_PORT_C      ENABLE

#define _RCC_ENABLE_ALTERNATIVE ENABLE

#define _RCC_ENABLE_UART_1      ENABLE
#define _RCC_ENABLE_UART_2      DISABLE
#define _RCC_ENABLE_UART_3      DISABLE
                               
#define _RCC_ENABLE_TIMER_2     DISABLE
#define _RCC_ENABLE_TIMER_3     DISABLE
                               
#define _RCC_ENABLE_SPI_1       ENABLE
                               
#define _RCC_ENABLE_MCO         DISABLE

#endif