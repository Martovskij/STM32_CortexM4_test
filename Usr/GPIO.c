#include "GPIO.h"




void gpioInit()
{
	GPIO_InitTypeDef gpio_init,gpio_a;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	gpio_init.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14| GPIO_Pin_15;
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
  gpio_init.GPIO_Mode = GPIO_Mode_OUT;
	gpio_init.GPIO_OType = GPIO_OType_PP;
	gpio_init.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &gpio_init);
	
	gpio_a.GPIO_Pin = GPIO_Pin_0;
	gpio_a.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_a.GPIO_Mode = GPIO_Mode_IN;
	gpio_a.GPIO_PuPd = GPIO_PuPd_DOWN;
  GPIO_Init(GPIOA, &gpio_a);	
}



