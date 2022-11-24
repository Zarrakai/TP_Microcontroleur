#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include <stdio.h>

int main ( void )
{
	
	MyGPIO_Struct_TypeDef GPIO_led, GPIO_btn ;
		
	GPIO_led.GPIO = GPIOC;
	GPIO_led.GPIO_Pin = 12;
	GPIO_led.GPIO_Conf = Out_Ppull;
	GPIO_led.odr = 0;
	MyGPIO_Init(& GPIO_led);
	
	
	GPIO_btn.GPIO = GPIOC;
	GPIO_btn.GPIO_Pin = 10;
	GPIO_btn.GPIO_Conf = In_PullUp;
	GPIO_btn.odr = 1;
	
	MyGPIO_Init(& GPIO_btn);
	
	do
	{
		if(MyGPIO_Read(GPIOC,10)) 	// si PC10 est à 0
		{
			MyGPIO_Set(GPIOC, 12);
		}
		else
		{
			MyGPIO_Reset(GPIOC, 12);
		}
		
	}while ( 1 ) ;
}
