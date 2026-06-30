#ifndef DEFINE_H
#define DEFINE_H

#include <stdint.h>

#define REG32(adr)  (*(volatile uint32_t*)(adr))

//RCC
#define RCC_BASE       0x40023800
#define RCC_AHB1ENR    REG32(RCC_BASE + 0X30)
#define RCC_APB2ENR    REG32(RCC_BASE + 0x44)

//GPIOA
#define GPIOA_BASE      0x40020000
#define GPIOA_MODER     REG32(GPIOA_BASE + 0x00)
#define GPIOA_OTYPER    REG32(GPIOA_BASE + 0x04)
#define GPIOA_OSPEEDR   REG32(GPIOA_BASE + 0x08)
#define GPIOA_PUPDR     REG32(GPIOA_BASE + 0x0C)
#define GPIOA_IDR       REG32(GPIOA_BASE + 0x10)
#define GPIOA_ODR       REG32(GPIOA_BASE + 0x14)
#define GPIOA_BSRR      REG32(GPIOA_BASE + 0x18)
#define GPIOA_LCKR      REG32(GPIOA_BASE + 0x1C)
#define GPIOA_AFRL      REG32(GPIOA_BASE + 0x20)
#define GPIOA_AFRH      REG32(GPIOA_BASE + 0x24)

//GPIOB
#define GPIOB_BASE      0x40020400
#define GPIOB_MODER     REG32(GPIOB_BASE + 0x00)
#define GPIOB_OTYPER    REG32(GPIOB_BASE + 0x04)
#define GPIOB_OSPEEDR   REG32(GPIOB_BASE + 0x08)
#define GPIOB_PUPDR     REG32(GPIOB_BASE + 0x0C)
#define GPIOB_IDR       REG32(GPIOB_BASE + 0x10)
#define GPIOB_ODR       REG32(GPIOB_BASE + 0x14)
#define GPIOB_BSRR      REG32(GPIOB_BASE + 0x18)
#define GPIOB_LCKR      REG32(GPIOB_BASE + 0x1C)
#define GPIOB_AFRL      REG32(GPIOB_BASE + 0x20)
#define GPIOB_AFRH      REG32(GPIOB_BASE + 0x24)

//GPIOC
#define GPIOC_BASE      0x40020800
#define GPIOC_MODER     REG32(GPIOC_BASE + 0x00)
#define GPIOC_OTYPER    REG32(GPIOC_BASE + 0x04)
#define GPIOC_OSPEEDR   REG32(GPIOC_BASE + 0x08)
#define GPIOC_PUPDR     REG32(GPIOC_BASE + 0x0C)
#define GPIOC_IDR       REG32(GPIOC_BASE + 0x10)
#define GPIOC_ODR       REG32(GPIOC_BASE + 0x14)
#define GPIOC_BSRR      REG32(GPIOC_BASE + 0x18)
#define GPIOC_LCKR      REG32(GPIOC_BASE + 0x1C)
#define GPIOC_AFRL      REG32(GPIOC_BASE + 0x20)
#define GPIOC_AFRH      REG32(GPIOC_BASE + 0x24)

//TIMER1
#define T1BASE_ADR     0x40010000
#define TIM1_CR1       REG32(T1BASE_ADR+0x00)
#define TIM1_CNT 	   REG32(T1BASE_ADR+0x24)
#define TIM1_PSC 	   REG32(T1BASE_ADR+0x28)
#define TIM1_ARR 	   REG32(T1BASE_ADR+0x2C)
#define TIM1_EGR 	   REG32(T1BASE_ADR+0x14)
#define TIM1_DIER      REG32(T1BASE_ADR+0x0C)
#define TIM1_SR    	   REG32(T1BASE_ADR+0x10)

//GPIOA MODER PIN
typedef struct {
	uint32_t PA0 :1;
	uint32_t PA1 :1;
	uint32_t PA2 :1;
	uint32_t PA3 :1;
	uint32_t PA4 :1;
	uint32_t PA5 :1;
	uint32_t PA6 :1;
	uint32_t PA7 :1;
	uint32_t PA8 :1;
	uint32_t PA9 :1;
	uint32_t PA10 :1;
	uint32_t PA11 :1;
	uint32_t PA12 :1;
	uint32_t PA13 :1;
	uint32_t PA14 :1;
	uint32_t PA15 :1;
	uint32_t :16;
} GPIOA_M;
#define GPIOA_PINM ((volatile GPIOA_M*) (GPIOA_BASE+0X00))

//GPIOB MODER PIN
typedef struct {
	uint32_t PB0 :1;
	uint32_t PB1 :1;
	uint32_t PB2 :1;
	uint32_t PB3 :1;
	uint32_t PB4 :1;
	uint32_t PB5 :1;
	uint32_t PB6 :1;
	uint32_t PB7 :1;
	uint32_t PB8 :1;
	uint32_t PB9 :1;
	uint32_t PB10 :1;
	uint32_t PB11 :1;
	uint32_t PB12 :1;
	uint32_t PB13 :1;
	uint32_t PB14 :1;
	uint32_t PB15 :1;
	uint32_t :16;
} GPIOB_M;
#define GPIOB_PINM (( volatile GPIOB_M*) (GPIOB_BASE+0X00))

//GPIOC MODER PIN
typedef struct {
	uint32_t PC0 :1;
	uint32_t PC1 :1;
	uint32_t PC2 :1;
	uint32_t PC3 :1;
	uint32_t PC4 :1;
	uint32_t PC5 :1;
	uint32_t PC6 :1;
	uint32_t PC7 :1;
	uint32_t PC8 :1;
	uint32_t PC9 :1;
	uint32_t PC10 :1;
	uint32_t PC11 :1;
	uint32_t PC12 :1;
	uint32_t PC13 :1;
	uint32_t PC14 :1;
	uint32_t PC15 :1;
	uint32_t :16;
} GPIOC_M;
#define GPIOC_PINM (( volatile GPIOC_M*) (GPIOC_BASE+0X00))

//GPIOA ODR PIN
typedef struct {
	uint32_t PA0 :1;
	uint32_t PA1 :1;
	uint32_t PA2 :1;
	uint32_t PA3 :1;
	uint32_t PA4 :1;
	uint32_t PA5 :1;
	uint32_t PA6 :1;
	uint32_t PA7 :1;
	uint32_t PA8 :1;
	uint32_t PA9 :1;
	uint32_t PA10 :1;
	uint32_t PA11 :1;
	uint32_t PA12 :1;
	uint32_t PA13 :1;
	uint32_t PA14 :1;
	uint32_t PA15 :1;
	uint32_t :16;
}GPIOA_O;
#define GPIOA_PINO ((volatile GPIOA_O *) (GPIOA_BASE + 0x14))

//GPIOB ODR PIN
typedef struct {
	uint32_t PB0 :1;
	uint32_t PB1 :1;
	uint32_t PB2 :1;
	uint32_t PB3 :1;
	uint32_t PB4 :1;
	uint32_t PB5 :1;
	uint32_t PB6 :1;
	uint32_t PB7 :1;
	uint32_t PB8 :1;
	uint32_t PB9 :1;
	uint32_t PB10 :1;
	uint32_t PB11 :1;
	uint32_t PB12 :1;
	uint32_t PB13 :1;
	uint32_t PB14 :1;
	uint32_t PB15 :1;
	uint32_t :16;
} GPIOB_O;
#define GPIOB_PINO (( volatile GPIOB_O*) (GPIOB_BASE + 0x14))

//GPIOC ODR PIN
typedef struct {
	uint32_t PC0 :1;
	uint32_t PC1 :1;
	uint32_t PC2 :1;
	uint32_t PC3 :1;
	uint32_t PC4 :1;
	uint32_t PC5 :1;
	uint32_t PC6 :1;
	uint32_t PC7 :1;
	uint32_t PC8 :1;
	uint32_t PC9 :1;
	uint32_t PC10 :1;
	uint32_t PC11 :1;
	uint32_t PC12 :1;
	uint32_t PC13 :1;
	uint32_t PC14 :1;
	uint32_t PC15 :1;
	uint32_t :16;
} GPIOC_O;
#define GPIOC_PINO (( volatile GPIOC_O*) (GPIOC_BASE + 0x14))

#endif
