/*
 * main.c
 *
 *  Created on: Jan 14, 2024
 *      Author: mrezk
 */

#include "..\04-LIB\BIT_MATH.h"
#include "..\04-LIB\STD_TYPES.h"
#include "..\01-MCAL\RCC\RCC_interface.h"


void main(void)
{

	RCC_voidInitSysClock();

   	RCC_ERR test=RCC_voidEnableClock(APB1, 3);
	test=RCC_voidEnableClock(APB2, 0);
	test=RCC_voidEnableClock(APB2, 1);
	test=RCC_voidEnableClock(APB2, 10);
	test=RCC_voidEnableClock(APB2, 15);
	test=RCC_voidEnableClock(APB2, 16);
	test=RCC_voidEnableClock(APB2, 17);
	test=RCC_voidEnableClock(APB2, 18);
	test=RCC_voidEnableClock(APB2, 19);
	test=RCC_voidEnableClock(APB2, 22);
	test=RCC_voidEnableClock(APB2, 23);
	test=RCC_voidEnableClock(APB2, 32);

	while(1)
	{

	}



}
