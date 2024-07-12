/*
 * NVIC_interface.h
 *
 *  Created on: Jun 28, 2024
 *      Author: mrezk
 */

#ifndef NVIC_NVIC_INTERFACE_H_
#define NVIC_NVIC_INTERFACE_H_

void MNVIC_voidSetInterrupt(u8 Copy_u8InterruptNumber,INTSTATE Copy_enuINTState);
void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber);
void MNVIC_voidSetPriority(s8 Copy_s8InterruptID,u8 copy_u8GroupPriority,u8 Copy_u8SubGroupPriority,u32 Copy_u32Group);

#endif /* NVIC_NVIC_INTERFACE_H_ */
