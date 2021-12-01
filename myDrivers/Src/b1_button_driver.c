/*
 * b1_button_driver.c
 *
 *  Created on: Nov 23, 2021
 *      Author: emin_
 */

#include "b1_button_driver.h"
#include "stm32f0xx_hal.h"


void button_init(void);

void button_init(void)
{
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef initStruct;

	initStruct.Pin=GPIO_PIN_13;
	initStruct.Mode=GPIO_MODE_INPUT ;
	initStruct.Pull=GPIO_NOPULL;
	initStruct.Speed=GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOC, &initStruct);

/*	__NVIC_EnableIRQ(EXTI4_15_IRQn)
	__NVIC_SetPriority(EXTI4_15_IRQn, 1);
*/
}

/*void EXTI4_15_IRQHandler(void)
{
	void spi_sendData(uint8_t *txBuffer,uint32_t length);
}*/
