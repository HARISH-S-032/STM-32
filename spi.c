
#include "spi.h"
#include "delay.h"

//void spi_bb_init_mode0_1(void)
//{
//    RCC_AHB1ENR |= (1<<1);
//
//    GPIOB_MODER   = 0x55555555;
//    GPIOB_OTYPER  = 0x00000000;
//    GPIOB_OSPEEDR = 0x55555555;
//    GPIOB_PUPDR   = 0x00000000;
//    GPIOB_ODR     = 0x00000000;
//
//    // PB2 as input (MISO)
//    GPIOB_MODER &= ~(3 << (2 * 2));
//
//    PORTB->PB5 = 1;   // CS
//    PORTB->PB1 = 0;   // SCK
//}

void spi_bb_init_mode0_1(void)
{
    RCC_AHB1ENR |= (1 << 1);      // Enable GPIOB clock

    GPIOB_MODER &= ~(3 << (1 * 2));
    GPIOB_MODER |=  (1 << (1 * 2));

    GPIOB_MODER &= ~(3 << (5 * 2));
    GPIOB_MODER |=  (1 << (5 * 2));

    GPIOB_MODER &= ~(3 << (13 * 2));
    GPIOB_MODER |=  (1 << (13 * 2));

    GPIOB_MODER &= ~(3 << (2 * 2));      // Input

    GPIOB_OTYPER &= ~((1<<1) | (1<<5) | (1<<13));

    GPIOB_OSPEEDR |= (2 << (1*2));
    GPIOB_OSPEEDR |= (2 << (5*2));
    GPIOB_OSPEEDR |= (2 << (13*2));

    GPIOB_PUPDR &= ~((3<<(1*2)) | (3<<(2*2)) | (3<<(5*2)) | (3<<(13*2)));

    // Initial States
    PORTB->PB5 = 1;      // CS High
    PORTB->PB1 = 0;      // Clock Low (SPI Mode 0)
    PORTB->PB13 = 0;     // MOSI Low
}
//
//void spi_bb_init_mode2_3(void)
//{
//	 RCC_AHB1ENR |= (1<<1);
//	  GPIOB_MODER =0X55555555;
//	  GPIOB_OTYPER=0X00000000;
//	  GPIOB_OSPEEDR=0X55555555;
//	  GPIOB_PUPDR=0X00000000;
//	  GPIOB_ODR=0X00000000;
//
//	  GPIOB_MODER &= ~(3 << (2 * 2));
//
//	  PORTB ->PB5=1;     //CS
//	  PORTB ->PB1=1;     //SCK
//
//}

//mode 0--------------------------------------------


void spi_write_mode0(unsigned char data)
{
	delay_ms(10);

	PORTB ->PB5=0;     //CS LOW
	 for(int i = 7; i >= 0; i--)
	 {

		 if(data & (1 << i))
		 PORTB ->PB13=1;        //MOSI

		 else
	      PORTB ->PB13=0;  //MOSI

		 PORTB ->PB1=1;     //CLK
		delay_us(5);
		 PORTB ->PB1=0;     //CLK
		 delay_us(5);
	 }


	 PORTB ->PB5=1;      //CS HIGH

}


void spi_write_mode0_16bit(uint16_t data)
{


	PORTB ->PB5=0;
	 for(int i = 15; i >= 0; i--)
	 {

		 if(data & (1 << i))
		 PORTB ->PB13=1;        //MOSI

		 else
	      PORTB ->PB13=0;  //MOSI

		 PORTB ->PB1=1;
		delay_us(5);
		 PORTB ->PB1=0;
		 delay_us(5);
	 }

	 PORTB ->PB5=1;             //HIGH CS
}


//mode 1--------------------------------------------


void spi_write_mode1(unsigned char data)
{
	init_delay_us();

	PORTB ->PB5=0;
	 for(int i = 7; i >= 0; i--)
	 {
		 PORTB ->PB1=1;
		 		 delay_us(5);
		 if(data & (1 << i))
		 PORTB ->PB13=1;        //mosi

		 else
	      PORTB ->PB13=0;  //mosi

		 PORTB ->PB1=0;
		 delay_us(5);
	 }

	 PORTB ->PB5=1;
}


//mode 2--------------------------------------------1

void spi_write_mode2(unsigned char data)
{
	init_delay_us();

	PORTB ->PB5=0;
	 for(int i = 7; i >= 0; i--)
	 {

		 if(data & (1 << i))
		 PORTB ->PB13=1;        //mosi

		 else
	      PORTB ->PB13=0;  //mosi

		 PORTB ->PB1=0;
		delay_us(5);
		 PORTB ->PB1=1;
		 delay_us(5);
	 }

	 PORTB ->PB5=1;
}


//mode 3--------------------------------------------


void spi_write_mode3(unsigned char data)
{
	init_delay_us();

	PORTB ->PB5=0;
	 for(int i = 7; i >= 0; i--)
	 {
		 PORTB ->PB1=0;
				delay_us(5);

		 if(data & (1 << i))
		 PORTB ->PB13=1;        //mosi

		 else
	      PORTB ->PB13=0;  //mosi


		 PORTB ->PB1=1;
		 delay_us(5);
	 }

	 PORTB ->PB5=1;
}

//
//uint8_t spi_transfer(uint8_t tx)
//{
//    uint8_t rx = 0;
//
//    PORTB->PB5 = 0;          // CS Low
//    delay_us(2);
//
//    for(int i = 7; i >= 0; i--)
//    {
//        // Put data on MOSI
//        if(tx & (1 << i))
//            PORTB->PB13 = 1;
//        else
//            PORTB->PB13 = 0;
//
//        delay_us(2);
//
//        // Rising edge - slave samples MOSI
//        PORTB->PB1 = 1;
//
//        // Master samples MISO
//        if(GPIOB_IDR & (1 << 2))
//            rx |= (1 << i);
//
//        delay_us(5);
//
//        // Falling edge
//        PORTB->PB1 = 0;
//
//        delay_us(2);
//    }
//
//    PORTB->PB5 = 1;          // CS High
//
//    return rx;
//}

void spi_slave_bb_init(void)
{
    RCC_AHB1ENR |= (1 << 1);      // Enable GPIOB clock


    GPIOB_MODER &= ~((3<<(1*2)) | (3<<(5*2)) | (3<<(13*2)));


    GPIOB_PUPDR &= ~((3<<(1*2)) | (3<<(5*2)) | (3<<(13*2)));
    GPIOB_PUPDR |=  ((2<<(1*2)) | (2<<(5*2)) | (2<<(13*2)));
}


uint8_t spi_slave_receive(void)
{
    uint8_t data = 0;

    while(GPIOB_IDR & (1 << 5));
    for(int i = 7; i >= 0; i--)
    {

        while(!(GPIOB_IDR & (1 << 1)));

        if(GPIOB_IDR & (1 << 13))
            data |= (1 << i);

        while(GPIOB_IDR & (1 << 1));
    }
   // while(!(GPIOB_IDR & (1 << 5)));

    return data;
}



uint8_t spi_transfer(uint8_t tx)
{
    uint8_t rx = 0;

    PORTB->PB5 = 0;

    for(int i = 7; i >= 0; i--)
    {
        if(tx & (1<<i))
            PORTB->PB13 = 1;
        else
            PORTB->PB13 = 0;
        delay_us(5);

        PORTB->PB1 = 1;

        if(GPIOB_IDR & (1<<2))
            rx |= (1<<i);
        delay_us(5);

        PORTB->PB1 = 0;
    }


    PORTB->PB5 = 1;

    return rx;
}
