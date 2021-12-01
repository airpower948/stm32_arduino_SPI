/*
 * spi_driver.c
 *
 *  Created on: Nov 23, 2021
 *      Author: emin_
 */

#include "spi_driver.h"
#include "stm32f0xx_hal.h"
#include <stdint.h>


void spi_init(void);
void spi_sendData(uint8_t *txBuffer,uint32_t length);
void spi_peripheral_control(uint8_t enordi);
void gpiob_init(void);
void spi_SSOEConfig(uint8_t enordi);

void spi_init(void)
{
	gpiob_init();

	__HAL_RCC_SPI2_CLK_ENABLE();

	SPI2->CR1 |= SPI_CR1_MSTR;
	SPI2->CR1 &= ~(SPI_CR1_BIDIMODE);
	SPI2->CR1 |= SPI_CR1_BR_0;
	SPI2->CR1 |= SPI_CR1_BR_1;
	SPI2->CR1 &= ~(SPI_CR1_BR_2);
	SPI2->CR1 &= ~(SPI_CR1_CRCL);
	SPI2->CR1 &= ~(SPI_CR1_CPHA);
	SPI2->CR1 &= ~(SPI_CR1_CPOL);
	SPI2->CR1 &= ~SPI_CR1_SSM;

}



void spi_sendData(uint8_t *txBuffer,uint32_t length)
{
	while(length>0)
	{
		while(!(SPI2->SR & SPI_SR_TXE));
		//if(SPI2->CR1 & SPI_CR1_CRCL)				//!(SPI2->CR1 &SPI_CR1_CRCL)
		//{
			SPI2->DR = *txBuffer;
			length--;
			txBuffer++;
		//}
		/*else
		{
			SPI2->DR = *((uint16_t*)txBuffer);
			length--;
			length--;
			(uint16_t*)txBuffer++;
		}*/
	}
}

void spi_peripheral_control(uint8_t enordi)
{
	if(enordi==ENABLE)
	{
		SPI2->CR1 |= SPI_CR1_SPE;
	}
	else
	{
		SPI2->CR1 &= ~SPI_CR1_SPE;
	}
}

void spi_SSOEConfig(uint8_t enordi)
{
	if(enordi==ENABLE)
	{
		SPI2->CR2 |= SPI_CR2_SSOE;
	}
	else
	{
		SPI2->CR2 &= ~SPI_CR2_SSOE;
	}
}
void gpiob_init(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef initStruct;

	initStruct.Pin=GPIO_PIN_12;
	initStruct.Mode=GPIO_MODE_AF_PP;
	initStruct.Pull=GPIO_NOPULL;
	initStruct.Alternate=GPIO_AF0_SPI2;
	HAL_GPIO_Init(GPIOB, &initStruct);

	initStruct.Pin=GPIO_PIN_13;
	HAL_GPIO_Init(GPIOB, &initStruct);

	//initStruct.Pin=GPIO_PIN_14;
	//HAL_GPIO_Init(GPIOB, &initStruct);

	initStruct.Pin=GPIO_PIN_15;
	HAL_GPIO_Init(GPIOB, &initStruct);
}

