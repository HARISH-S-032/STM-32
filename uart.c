#include <stdint.h>
#include "define.h"
#include "uart.h"
#include "delay.h"

void uart_init(uint32_t port,uint8_t tx,uint8_t rx,uint32_t baud)
{
	init_delay_us();
	
	GPIOB_PINO->PB5=1;
}
void uart_transmit(char *data)
{
    uint8_t temp;

    while(*data)
    {
        temp = *data;

        // Start bit
        GPIOB_PINO->PB5=0;
        delay_us(104);

        // Data bits
        for(uint8_t i=0;i<8;i++)
        {
            if(temp & (1<<i))
            	GPIOB_PINO->PB5=1;
            else
            	GPIOB_PINO->PB5=0;

            delay_us(104);
        }

        // Stop bit
        GPIOB_PINO->PB5=1;
        delay_us(104);

        data++;
    }
}
