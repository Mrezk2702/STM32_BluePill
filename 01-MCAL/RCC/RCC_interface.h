/*
 * RCC_interface.h
 *
 *  Created on: Jan 7, 2024
 *      Author: mrezk
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
typedef enum
{
	APB1=2,
	APB2=4,
	AHB=6
}BusType;

typedef enum
{
	NO_ERROR=0,
	BIT_OUT_OFBOUNDS=2,
	WRONG_BUS=4,
	RESERVED_BIT=6,


}RCC_ERR;



void RCC_voidInitSysClock(void);

RCC_ERR RCC_voidEnableClock(BusType Copy_enmBusName,u8 Copy_u8PeriphID);
#endif /* RCC_INTERFACE_H_ */
