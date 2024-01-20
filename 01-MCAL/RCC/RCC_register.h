/*
 * RCC_register.h
 *
 *  Created on: Jan 7, 2024
 *      Author: mrezk
 */


#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_


#define RCC_BASE_ADDRESS 0x40021000





#define RCC_CR_REG ((volatile  RCC_CR *) (RCC_BASE_ADDRESS + 0x00))
#define RCC_CFG_REG ((volatile  RCC_CFGR *) (RCC_BASE_ADDRESS + 0x04))
#define RCC_APB2RSTR_REG	*((volatile  u32 *) (RCC_BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR_REG *((volatile u32 *)( RCC_BASE_ADDRESS + 0x10))
#define RCC_AHBENR_REG	*((volatile u32*) (RCC_BASE_ADDRESS+0x14))
#define RCC_APB2ENR_REG *((volatile u32 *)(RCC_BASE_ADDRESS+0x18))
#define RCC_APB1ENR_REG *((volatile u32 *)(RCC_BASE_ADDRESS+0x1C))







#endif /* RCC_REGISTER_H_ */
