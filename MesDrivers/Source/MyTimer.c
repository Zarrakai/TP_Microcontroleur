#include "stm32f10x.h"
#include "MyTimer.h"

void (*ptFonction ) ( void );

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer )
	{
		Timer ->Timer->ARR = Timer->ARR;
	  Timer ->Timer->PSC = Timer->PSC; 		
}
	
/*
void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio)
{
	int interruptNumber ;
	Timer->DIER |= TIM_DIER_UIE;	// on active UIE
	Timer->SR &= ~(0x01);
	
	
	if (Timer == TIM1 ){
		interruptNumber = TIM1_CC_IRQn ;
	}
	else if (Timer == TIM2 ){
		interruptNumber = TIM2_IRQn;
	}
	else if (Timer == TIM3){
		interruptNumber = TIM3_IRQn;
	}
	else if (Timer == TIM4){
		interruptNumber = TIM4_IRQn;
	}
	NVIC_EnableIRQ(interruptNumber);
	NVIC_SetPriority(interruptNumber, Prio);
}*/

void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio , void (*IT_function ) ( void )) 
{
	int interruptNumber ;
	Timer->DIER |= TIM_DIER_UIE;	// on active UIE
	Timer->SR &= ~(0x01);
	
	
	if (Timer == TIM1 ){
		interruptNumber = TIM1_CC_IRQn ;
	}
	else if (Timer == TIM2 ){
		interruptNumber = TIM2_IRQn;
	}
	else if (Timer == TIM3){
		interruptNumber = TIM3_IRQn;
	}
	else if (Timer == TIM4){
		interruptNumber = TIM4_IRQn;
	}
	NVIC_EnableIRQ(interruptNumber);
	NVIC_SetPriority(interruptNumber, Prio);
	
	ptFonction = IT_function;
}
/*
// redéfinition de TIM2_IRQHandler
void TIM2_IRQHandler(void)
{
	// désactivation de UIF
	TIM2->SR &= ~(0x01);
	
}*/
void TIM2_IRQHandler(void)
{
	// désactivation de UIF
	TIM2->SR &= ~(0x01);
	(*ptFonction)();
	
}

void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) 
{
	
}