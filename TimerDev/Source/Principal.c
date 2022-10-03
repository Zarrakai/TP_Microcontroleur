#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"



void clignotant(void);

MyGPIO_Struct_TypeDef GPIO_led;
MyTimer_Struct_TypeDef timer ;
int main ( void )
{
		
	int compteur = 0;
	double periodeTimer_ms;
	double periode_Horloge_ms;
	
	GPIO_led.GPIO = GPIOC;
	GPIO_led.GPIO_Pin = 12;
	GPIO_led.GPIO_Conf = Out_Ppull;
	GPIO_led.odr = 0;
	MyGPIO_Init(&GPIO_led);
	
	timer.ARR = 3599;
	timer.PSC = 9999;
	timer.Timer =TIM2;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	MyTimer_Base_Init(&timer);
	MyTimer_Base_Start(timer.Timer);
	
	//MyTimer_ActiveIT(timer.Timer, 0);
	MyTimer_ActiveIT(timer.Timer, 1, &clignotant);
	
	
	// Periode timer = Periode_Horloge * (PSC + 1) * (ARR + 1)
	//periode_Horloge_ms = (10^3) * 1/(72*10^6);
	//periodeTimer_ms = periode_Horloge_ms * (TIM2->PSC + 1) * (TIM2->ARR + 1);
	
	
	do
	{
		
	}while ( 1 ) ;
}
void clignotant(void)
{
	
	MyGPIO_Toggle(GPIO_led.GPIO, GPIO_led.GPIO_Pin);	//à définir 
}
