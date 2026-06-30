#include <stdint.h>
#include "delay.h"

void init_delay_us()
{
	    RCC_APB2ENR |= (1<<0);
		TIM1_PSC=15;
//		TIM1_ARR=0XFFFF;
		TIM1_EGR |= (1<<0);
//		TIM1_DIER|=(1<<0);
//		NVIC_ISER0 |= (1<<25);
//		TIM1_CR1=TIM1_CR1|(1<<7)|(1<<0);
}

void delay_us(uint16_t time)
{
	TIM1_CNT = 0;
	TIM1_CR1|=(1<<0);
	while(TIM1_CNT<time-3);
}
