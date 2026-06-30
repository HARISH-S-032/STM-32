#ifndef UART_H
#define UART_H

#include <stdint.h>

/* Function Prototypes */

void uart_init(void);
void uart_transmit(char *data);

#endif /* UART_BITBANG_H_ */
