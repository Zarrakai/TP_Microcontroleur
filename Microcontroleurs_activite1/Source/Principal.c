#include "stm32f10x.h"


#define PullUpDwn	8
#define PushPull	2
#define OpenDrain 6

int main ( void )
{
	//RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |RCC_APB2ENR_IOPBEN |RCC_APB2ENR_IOPCEN ;
	
	// configuration
	//PC12 => LED
	GPIOC->CRH &= ~(0xf << (18-16)*8);	//mise à 0 du champs CNF et MODE de PC12
	GPIOC->CRH |= (PushPull << (18-16)*8);
	//GPIOC->CRH |= (OpenDrain << (18-16)*8);
	GPIOC->ODR &= ~(0x01 << 12);
	
	
	//PC10 => BTN
	GPIOC->CRH &= ~(0xf << (10-8)*4);	//mise à 0 du champs CNF et MODE de PC10
	GPIOC->CRH |= (PullUpDwn << (10-8)*4);	  // 8 = pullup/down
	GPIOC->ODR |= (0x01 << 10);
	
	
	
	do
	{
		if((GPIOC->IDR & GPIO_ODR_ODR10) >> 10 == 0) 	// si PC10 est à 0
		{
			GPIOC->ODR |= GPIO_ODR_ODR12;
		}
		else
		{
			GPIOC->ODR &= ~(0x01 << 12);
		}
		
	}while ( 1 ) ;
}
