/*
 * NVIC_prog.c
 *
 *  Created on: Jun 28, 2024
 *      Author: mrezk
 */


/********Inlcudes********/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_private.h"
#include "NVIC_register.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"


void MNVIC_voidSetInterrupt(u8 Copy_u8InterruptNumber,INTSTATE Copy_enuINTState)
{
	if(Copy_u8InterruptNumber<=NUMBER_OF_VECTORS)
	{
		if(Copy_u8InterruptNumber<32)
		{/*ISER0*/
			if(Copy_enuINTState==ENABLE)
			{

				NVIC_ISER0_REG=1<<Copy_u8InterruptNumber;
			}
			else if(Copy_enuINTState==DISABLE)
			{

				NVIC_ICER0_REG=1<<Copy_u8InterruptNumber;
			}
			else
			{
				/*Do nothing*/
			}
		}
		else
		{/*ISER1 and ICER1*/
			Copy_u8InterruptNumber=Copy_u8InterruptNumber-32;
			if(Copy_enuINTState==ENABLE)
			{

				NVIC_ISER1_REG=1<<Copy_u8InterruptNumber;
			}
			else if(Copy_enuINTState==DISABLE)
			{
				NVIC_ICER1_REG=1<<Copy_u8InterruptNumber;
			}
			else
			{
				/*Do nothing*/
			}
		}

	}
	else
	{

		/*return error state*/
	}
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber)
{

	if(Copy_u8InterruptNumber<=NUMBER_OF_VECTORS)
	{
		if(Copy_u8InterruptNumber<32)
		{/*ISPR0*/
			NVIC_ISPR0_REG=1<<Copy_u8InterruptNumber;
		}
		else
		{/*ISPR1*/
			Copy_u8InterruptNumber=Copy_u8InterruptNumber-32;
			NVIC_ISPR1_REG=1<<Copy_u8InterruptNumber;
		}

	}
	else
	{
		/*return error state*/
	}
}



void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptNumber)
{

	if(Copy_u8InterruptNumber<=NUMBER_OF_VECTORS)
	{
		if(Copy_u8InterruptNumber<32)
		{/*ICPR0*/
			NVIC_ICPR0_REG=1<<Copy_u8InterruptNumber;
		}
		else
		{/*ICPR1*/
			Copy_u8InterruptNumber=Copy_u8InterruptNumber-32;
			NVIC_ICPR1_REG=1<<Copy_u8InterruptNumber;
		}

	}
	else
	{
		/*return error state*/
	}
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber)
{
	u8 loc_u8Returnresult=0;
	if(Copy_u8InterruptNumber<=NUMBER_OF_VECTORS)
		{
			if(Copy_u8InterruptNumber<32)
			{/*ICPR0*/
				loc_u8Returnresult=GET_BIT(NVIC_IABR0_REG,Copy_u8InterruptNumber);
			}
			else
			{/*ICPR1*/
				Copy_u8InterruptNumber=Copy_u8InterruptNumber-32;
				loc_u8Returnresult=GET_BIT(NVIC_IABR1_REG,Copy_u8InterruptNumber);
			}

		}
		else
		{
			/*do nothing*/
		}
	return loc_u8Returnresult;
}


void MNVIC_voidSetPriority(s8 Copy_s8InterruptID,u8 copy_u8GroupPriority,u8 Copy_u8SubGroupPriority,u32 Copy_u32Group)
{
	/*Whether interrupt ID is core peripheral
	 * or external peripheral*/

	u8 loc_u8Priority=Copy_u8SubGroupPriority|copy_u8GroupPriority<<((Copy_u32Group-0x05FA0300)/256) ;
	if(Copy_s8InterruptID>=0&&Copy_s8InterruptID<=NUMBER_OF_VECTORS)
	{
		NVIC_IPR0[Copy_s8InterruptID]=loc_u8Priority<<4;
	}
	SCB_AIRCR_REG=Copy_u32Group;





}
