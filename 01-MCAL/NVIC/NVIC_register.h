/*
 * NVIC_register.h
 *
 *  Created on: Jun 28, 2024
 *      Author: mrezk
 *      Version: V1.0
 */

#ifndef NVIC_NVIC_REGISTER_H_
#define NVIC_NVIC_REGISTER_H_



#define NVIC_BASE_ADDRESS 0xE000E100
#define SCB_BASE_ADDRESS		0xE000ED00

#define NVIC_ISER0_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x00))
#define NVIC_ISER1_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x04))

#define NVIC_ICER0_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x80))
#define NVIC_ICER1_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x84))

#define NVIC_ISPR0_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x104))

#define NVIC_ICPR0_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x184))

#define NVIC_IABR0_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1_REG *((volatile u32*)(NVIC_BASE_ADDRESS+0x204))

#define NVIC_IPR0		((volatile u8 *)(NVIC_BASE_ADDRESS+0x300))


#define SCB_AIRCR_REG *((volatile u32 *)(SCB_BASE_ADDRESS+0x0C))

#endif /* NVIC_NVIC_REGISTER_H_ */
