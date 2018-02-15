#ifndef _GPIO_INTERFACE_
#define _GPIO_INTERFACE_

/* #DEFINES# */



/* #VARIBLES# */
enum PORTS{PORTA,PORTB,PORTC,PORTD,PORTE,PORTF,PORTG};
enum PINS{PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15};
enum DIRECTIONS{OUT_10MHZ,OUT_2MHZ,OUT_50MHZ,INPUT};
enum CONFG {OUT_GP_PUSH_PULL,
            OUT_GP_OPEN_DRAIN,
            OUT_AF_PUSH_PULL,
            OUT_AF_OPEN_DRAIN,
            IN_ANALOG,
            IN_FLOAT,
            IN_PULLUD};
enum STATE{LOW,HIGH,TOGGLE};


/* #FUNCTION_PROTOTYPES# */

/*
INPUT(Port)     >> select from enum PORTS{}
INPUT(Pin)      >> select from enum PINS{}
INPUT(Direction)>> select from enum DIRECTIONS{}
INPUT(Cnfg)>> select from enum CONFG{}
*/
extern void GPIO_voidSetPinDirection(U8 Port,U8 Pin,U8 Direction, U8 Confg);

/*
INPUT(Port)     >> select from enum PORTS{}
INPUT(Pin)      >> select from enum PINS{}
INPUT(Value)>> select from enum STATE{}
*/
extern void GPIO_voidSetPinValue(U8 Port,U8 Pin,U8 Value);
/*
INPUT(Port)     >> select from enum PORTS{}
INPUT(Pin)      >> select from enum PINS{}
OUTPUT(STATE)   >> LOW or HIGH
*/
U8   GPIO_U8GetPinValue(U8 Port,U8 Pin);

/*
INPUT(Port)     >> select from enum PORTS{}
INPUT(Pin)      >> select from enum PINS{}
*/
extern void GPIO_voidSetPullUp  (U8 Port,U8 Pin);
extern void GPIO_voidSetPullDown(U8 Port,U8 Pin);

#endif