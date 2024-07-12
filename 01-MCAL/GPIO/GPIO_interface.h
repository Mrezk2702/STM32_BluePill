#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*Includes*/


/*Global variables*/

/*Local Variables*/


/*Data types*/
typedef enum
{
	PORTA=2,
	PORTB=4,
	PORTC=6
}PORT_INDEX;

typedef enum
{
	PIN_OUT_OF_RANGE=2,
	WRONG_PORT=4,
	WRONG_DATA=6,
	GPIO_NO_ERROR=8
}SetPIN_Err_State;

extern SetPIN_Err_State Global_EnuSetPinErrorState;


/*Function prototypes*/
void GPIO_voidInit(void);
void GPIO_voidSetPinValue(PORT_INDEX Cpy_enuPortIndx,u8 Cpy_PinNumber,b Cpy_bData);

#endif
