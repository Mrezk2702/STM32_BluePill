/*
 * RCC_private.h
 *
 *  Created on: Jan 7, 2024
 *      Author: mrezk
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


typedef struct
{
	u32 HSION:1;
	u32 HSIRDY:1;
	u32 :1;
	u32 HSITRIM:5;
	u32 HSICAL:8;
	u32 HSEON:1;
	u32 HSREDY:1;
	u32 HSEBYP:1;
	u32 CSSON:1;
	u32 :4;
	u32 PLLON:1;
	u32 PLLRDY:1;
	u32 :6;

}RCC_CR;



typedef struct
{
	u32 SW:2;
	u32 SWS:2;
	u32 HPRE:4;
	u32 PPRE1:3;
	u32 PPRE2:3;
	u32 ADC_PRE:2;
	u32 PLL_SRC:1;
	u32 PLL_XTPRE:1;
	u32 PLLMUL:4;
	u32 OTGFSPRE:1;
	u32 :1;
	u32 MCO:3;
	u32:4;

}RCC_CFGR;







#define ENABLE 	1
#define DISABLE 0


/*System clock*/
#define HSI_SYSTEM_CLOCK 0
#define HSE_SYSTEM_CLOCK 0b01
#define PPL_SYSTEMCLOCK 0b10

/*PLL input clock factors*/
#define PLL_INPUT_CLOCK_X_2		0b0000u
#define PLL_INPUT_CLOCK_X_3     0b0001u
#define PLL_INPUT_CLOCK_X_4     0b0010u
#define PLL_INPUT_CLOCK_X_5     0b0011u
#define PLL_INPUT_CLOCK_X_6     0b0100u
#define PLL_INPUT_CLOCK_X_7     0b0101u
#define PLL_INPUT_CLOCK_X_8     0b0110u
#define PLL_INPUT_CLOCK_X_9     0b0111u
#define PLL_INPUT_CLOCK_X_10    0b1000u
#define PLL_INPUT_CLOCK_X_11    0b1001u
#define PLL_INPUT_CLOCK_X_12    0b1010u
#define PLL_INPUT_CLOCK_X_13    0b1011u
#define PLL_INPUT_CLOCK_X_14    0b1100u
#define PLL_INPUT_CLOCK_X_15    0b1101u
#define PLL_INPUT_CLOCK_X_16    0b1110u
#define PLL_INPUT_CLOCK_X_16_2    0b1111u

/*APB1 and APB2 PRESCALER*/
#define HCLK_NODIV 		0b000
#define HCLK_BY2		0b100
#define HCLK_BY4		0b101
#define HCLK_BY8		0b110
#define HCLK_BY16		0b111

/*ADC PRESACLER OPTIONS*/
 #define PCLK2_DIVIDED_BY_2    0b00
 #define PCLK2_DIVIDED_BY_4    0b01
 #define PCLK2_DIVIDED_BY_6    0b10
 #define PCLK2_DIVIDED_BY_8    0b11

/*AHB PRESCALER*/
#define SYSCLK_NOT_DIVIDED       0b0000
#define SYSCLK_DIVIDED_BY_2      0b1000
#define SYSCLK_DIVIDED_BY_4      0b1001
#define SYSCLK_DIVIDED_BY_8      0b1010
#define SYSCLK_DIVIDED_BY_16     0b1011
#define SYSCLK_DIVIDED_BY_64     0b1100
#define SYSCLK_DIVIDED_BY_128    0b1101
#define SYSCLK_DIVIDED_BY_256    0b1110
#define SYSCLK_DIVIDED_BY_512    0b1111


/*PLL clock source*/
#define HSE_PLL_SOURCE 1
#define HSI_DIV_BY2_PLL_SOURCE 0

#define HSE_DIVIDED_BY_2 1
#define HSE_NOT_DIVIDED 0

#endif /* RCC_PRIVATE_H_ */
