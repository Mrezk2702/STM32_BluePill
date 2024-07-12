


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_register.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

#include "GPIO_interface.h"

/*Global Variables*/
SetPIN_Err_State Global_EnuSetPinErrorState;


void GPIO_voidInit(void)
{
	GPIO_PORTA->CRL=PORTA_CRL_INIT;


	GPIO_PORTA->CRH=PORTA_CRH_INIT;


	GPIO_PORTB->CRL=PORTB_CRL_INIT;

	GPIO_PORTB->CRH=PORTB_CRH_INIT;
}

void GPIO_voidSetPinValue(PORT_INDEX Cpy_enuPortIndx,u8 Cpy_PinNumber,b Cpy_bData)
{
	Global_EnuSetPinErrorState=GPIO_NO_ERROR;
	if(Cpy_PinNumber>15)
	{
		/*Wrong input*/
		Global_EnuSetPinErrorState=PIN_OUT_OF_RANGE;
	}
	else
	{
		/*execute the function normally*/

		switch (Cpy_enuPortIndx)
		{
		case PORTA:
			if(Cpy_bData==STD_bTRUE)
			{
				SET_BIT(GPIO_PORTA->ODR,Cpy_PinNumber);
			}
			else if(Cpy_bData==STD_bFALSE)
			{
				CLEAR_BIT(GPIO_PORTA->ODR,Cpy_PinNumber);
			}
			else
			{
				Global_EnuSetPinErrorState=WRONG_DATA;
			}
			break;
		case PORTB:

			if(Cpy_bData==STD_bTRUE)
			{
				SET_BIT(GPIO_PORTB->ODR,Cpy_PinNumber);
			}
			else if(Cpy_bData==STD_bFALSE)
			{
				CLEAR_BIT(GPIO_PORTB->ODR,Cpy_PinNumber);
			}
			else
			{
				Global_EnuSetPinErrorState=WRONG_DATA;
			}
			break;

		case PORTC:
			if(Cpy_bData==STD_bTRUE)
			{
				SET_BIT(GPIO_PORTC->ODR,Cpy_PinNumber);
			}
			else if(Cpy_bData==STD_bFALSE)
			{
				CLEAR_BIT(GPIO_PORTC->ODR,Cpy_PinNumber);
			}
			else
			{
				Global_EnuSetPinErrorState=WRONG_DATA;
			}
			break;

		default:

		}
	}
}
