#ifndef SPI_H
#define SPI_H

#include "define.h"
#include <stdint.h>

void spi_bb_init_mode0_1(void);
void spi_bb_init_mode2_3(void);
uint8_t spi_slave_receive(void);
void spi_slave_bb_init(void);
void spi_write_mode0(unsigned char data);
void spi_write_mode1(unsigned char data);
void spi_write_mode2(unsigned char data);
void spi_write_mode3(unsigned char data);


void spi_write_mode0_16bit(uint16_t data);
uint8_t spi_transfer(uint8_t tx);

#endif
