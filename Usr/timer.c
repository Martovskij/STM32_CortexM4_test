#include "timer.h"



void timerInit(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);  // enable clock
	NVIC_EnableIRQ(TIM7_IRQn); // enable irq
	TIM7->ARR = 500;
	TIM7->DIER|=TIM_DIER_UIE;
	TIM7->PSC = 24000;
	TIM7->CR1|=TIM_CR1_CEN ; // start counter
}
