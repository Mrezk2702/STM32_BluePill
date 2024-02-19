


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_register.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

#include "GPIO_interface.h"




void GPIO_voidInit(void)
{
	GPIO_PORTA->CRL=PORTA_CRL_INIT;


	GPIO_PORTA->CRH=PORTA_CRH_INIT;


	GPIO_PORTB->CRL=PORTB_CRL_INIT;


	GPIO_PORTB->CRH=PORTB_CRH_INIT;
}
