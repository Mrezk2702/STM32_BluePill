/*
 * RCC.c
 *
 *  Created on: Jan 7, 2024
 *      Author: mrezk
 */


#include "..\..\04-LIB\BIT_MATH.h"
#include "..\..\04-LIB\STD_TYPES.h"
#include "RCC_private.h"

#include "RCC_register.h"
#include "RCC_config.h"
#include "RCC_interface.h"



void RCC_voidInitSysClock(void)
{


	/*System Clock*/
	RCC_CFG_REG->SW=SYSTEM_CLOCK;


#if HSE_CLOCK==ENABLE &&HSE_BYPASS==ENABLE
	RCC_CR_REG->HSEBYP=1;

#else
	RCC_CR_REG->HSEBYP=0;
#endif


#if HSE_CLOCK==ENABLE
	RCC_CR_REG->HSEON=1;
#elif HSE_CLOCK==DISABLE
	//RCC_CR_REG->HSEON=0;
#endif


	/*AHB PRESACLER*/
	RCC_CFG_REG->HPRE=AHB_PRESCALER;

	/*APB1 prescaler*/
	RCC_CFG_REG->PPRE2=APB2_PRESCALER;

	/*APB2 prescaler*/
	RCC_CFG_REG->PPRE1=APB1_PRESCALER;

	/*ADC PRESACLER*/
	RCC_CFG_REG->ADC_PRE=ADC_PRESCALER;




	/*PLL Clock Source*/
	RCC_CFG_REG->PLL_SRC=PLL_CLOCK_SRC;

	RCC_CFG_REG->PLL_XTPRE=HSE_DIVIDER;
	/*PLL input factor*/
	RCC_CFG_REG->PLLMUL=PLL_INPUT_CLOCK_FACTOR;
#if PLL_CLOCK==ENABLE
	RCC_CR_REG->PLLON=1;
#elif PLL_CLOCK==DISABLE
	RCC_CR_REG->PLLON=0;
#endif



#if HSI_CLOCK ==ENABLE
	RCC_CR_REG->HSION=1;
#elif HSI_CLOCK==DISABLE
	RCC_CR_REG->HSION=0;
#endif

#if RCC_CR_CSSON==ENABLE
	RCC_CR_REG->CSSON=1;

#elif RCC_CR_CSSON==DISABLE
	RCC_CR_REG->CSSON=0;
#endif


	while(RCC_CR_REG->HSREDY==0&&RCC_CR_REG->HSIRDY==0&&RCC_CR_REG->PLLRDY==0)
	{
		/*wait for any clock to be ready*/
	}










}


RCC_ERR RCC_voidEnableClock(BusType Copy_enmBusName,u8 Copy_u8PeriphID)
{
	RCC_ERR loc_enmRCC_ERR=NO_ERROR;
	if(Copy_u8PeriphID<=31u)// @suppress("Avoid magic numbers")
	{
		/*Function Body*/
		switch (Copy_enmBusName)
		{
		case AHB:
			if(Copy_u8PeriphID<=10||Copy_u8PeriphID!=3||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=5||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=7|| // @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=9)// @suppress("Avoid magic numbers")
			{
				SET_BIT(RCC_AHBENR_REG,Copy_u8PeriphID);
			}
			else
			{
				/*Error*/
				loc_enmRCC_ERR=RESERVED_BIT;
			}

			break;

		case APB1:
			if(Copy_u8PeriphID!=10||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=9||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=11||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=12||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=16||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=24||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID!=26||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID<30)// @suppress("Avoid magic numbers")
			{
				SET_BIT(RCC_APB1ENR_REG,Copy_u8PeriphID);

			}
			else
			{
				/*Error*/
				loc_enmRCC_ERR=RESERVED_BIT;
			}

			break;

		case APB2:

			if(Copy_u8PeriphID!=1||
					Copy_u8PeriphID<16||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID>18||// @suppress("Avoid magic numbers")
					Copy_u8PeriphID<22)// @suppress("Avoid magic numbers")
			{
				SET_BIT(RCC_APB1ENR_REG,Copy_u8PeriphID);
			}
			else
			{
				/*Error*/
				loc_enmRCC_ERR=RESERVED_BIT;
			}

			break;
		default:

			/*Error state*/
			loc_enmRCC_ERR=WRONG_BUS;
		}

	}
	else
	{

		/*Error State*/
		loc_enmRCC_ERR=BIT_OUT_OFBOUNDS;
	}


	return loc_enmRCC_ERR;

}
