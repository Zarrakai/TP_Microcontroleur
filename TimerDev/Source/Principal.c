#include "stm32f10x.h"
#include "MyTimer.h"




MyTimer_Struct_TypeDef timer ;
int main ( void )
{
	double periodeTimer_ms;
	double periode_Horloge_ms;
	timer.ARR = 3599;
	timer.PSC = 9999;
	timer.Timer =TIM2;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	MyTimer_Base_Init(&timer);
	MyTimer_Base_Start(timer.Timer);
	
	// Periode timer = Periode_Horloge * (PSC + 1) * (ARR + 1)
	
	
	
	//periode_Horloge_ms = (10^3) * 1/(72*10^6);
	//periodeTimer_ms = periode_Horloge_ms * (TIM2->PSC + 1) * (TIM2->ARR + 1);
	
	
	do
	{
		
	}while ( 1 ) ;
}
