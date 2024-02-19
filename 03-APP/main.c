/*
 * main.c
 *
 *  Created on: Jan 14, 2024
 *      Author: mrezk
 */

#include "..\04-LIB\BIT_MATH.h"
#include "..\04-LIB\STD_TYPES.h"
#include "..\01-MCAL\RCC\RCC_interface.h"
#include "GPIO_interface.h"

void main(void)
{

	RCC_voidInitSysClock();

   	RCC_ERR test=RCC_voidEnableClock(APB2, 2);

   	GPIO_voidInit();

	while(1)
	{

	}



}
