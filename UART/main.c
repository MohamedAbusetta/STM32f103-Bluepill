#include "../Vertical Layer/Datatypes.h"
#include "../RCC/RCC_interface.h"
#include "../UART/UART_interface.h"
#include "../RCC/RCC_interface.h"


void main( void )
{ 
  U8 Data = 'c';
    RCC_voidInitSysClock();
    UART1_voidInit();
    while(1)
    {
      
      Data = UART1_U8Recive();
      UART1_voidSend(Data);
      
      
    }
    
}
