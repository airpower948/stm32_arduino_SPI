/*
 * spi_driver.h
 *
 *  Created on: Nov 23, 2021
 *      Author: emin_
 */

#ifndef MYDRIVERS_INC_SPI_DRIVER_H_
#define MYDRIVERS_INC_SPI_DRIVER_H_

#include <stdint.h>


void spi_init(void);
void spi_sendData(uint8_t *txBuffer,uint32_t length);
void spi_peripheral_control(uint8_t enordi);
void spi_SSOEConfig(uint8_t enordi);

#endif /* MYDRIVERS_INC_SPI_DRIVER_H_ */
