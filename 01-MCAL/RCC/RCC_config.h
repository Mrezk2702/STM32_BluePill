/*
 * RCC_config.h
 *
 *  Created on: Jan 7, 2024
 *      Author: mrezk
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*Configuration Options
 * ENABLE
 * DISABLE
 * */
#define PLL_CLOCK ENABLE
#define HSI_CLOCK ENABLE
#define HSE_CLOCK DISABLE
#define RCC_CR_CSSON DISABLE
#define HSE_BYPASS ENABLE


/*Configuration options for system clock
 *1: HSI_SYSTEM_CLOCK
 *2: HSE_SYSTEM_CLOCK
 *3: PPL_SYSTEMCLOCK */
#define SYSTEM_CLOCK PPL_SYSTEMCLOCK


/*
 * PLL_INPUT_CLOCK_X_2
 *PLL_INPUT_CLOCK_X_3
 *PLL_INPUT_CLOCK_X_4
 *PLL_INPUT_CLOCK_X_5
 *PLL_INPUT_CLOCK_X_6
 *PLL_INPUT_CLOCK_X_7
 *PLL_INPUT_CLOCK_X_8
 *PLL_INPUT_CLOCK_X_9
 *PLL_INPUT_CLOCK_X_10
 *PLL_INPUT_CLOCK_X_11
 *PLL_INPUT_CLOCK_X_12
 *PLL_INPUT_CLOCK_X_13
 *PLL_INPUT_CLOCK_X_14
 *PLL_INPUT_CLOCK_X_15
 *PLL_INPUT_CLOCK_X_16
 *PLL_INPUT_CLOCK_X_16
 * */
#define PLL_INPUT_CLOCK_FACTOR PLL_INPUT_CLOCK_X_10



/*Configuration Options for AHB PRESCALER
 * SYSCLK_NOT_DIVIDED
 *SYSCLK_DIVIDED_BY_2
 *SYSCLK_DIVIDED_BY_4
 *SYSCLK_DIVIDED_BY_8
 *SYSCLK_DIVIDED_BY_16
 *SYSCLK_DIVIDED_BY_64
 *SYSCLK_DIVIDED_BY_128
 *SYSCLK_DIVIDED_BY_256
 *SYSCLK_DIVIDED_BY_512*/
#define AHB_PRESCALER SYSCLK_NOT_DIVIDED

/*Configuration Options
 * APB1_PRESCALER_NODIV
 * APB1_PRESACLER_BY2
 * APB1_PRESACLER_BY4
 * APB1_PRESACLER_BY8
 * APB1_PRESACLER_BY16
 *
 * */
#define APB1_PRESCALER HCLK_BY2

#define APB2_PRESCALER HCLK_NODIV


/*Configuration option:
 * HSE_PLL_SOURCE
 * HSI_DIV_BY2_PLL_SOURCE
 * */
#define PLL_CLOCK_SRC HSI_DIV_BY2_PLL_SOURCE

#define HSE_DIVIDER HSE_NOT_DIVIDED

/*ADC PRESACLER OPTIONS
 PCLK2_DIVIDED_BY_2
 PCLK2_DIVIDED_BY_4
 PCLK2_DIVIDED_BY_6
 PCLK2_DIVIDED_BY_8
*/
#define ADC_PRESCALER PCLK2_DIVIDED_BY_2

#endif /* RCC_CONFIG_H_ */