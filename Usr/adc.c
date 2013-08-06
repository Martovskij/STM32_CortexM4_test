#include "adc.h"




void adcInit(void)
{
	ADC_InitTypeDef  adc_init;
	GPIO_InitTypeDef adc_gpio;
	ADC_CommonInitTypeDef adc_common;
	adc_gpio.GPIO_Mode =  GPIO_Mode_AN;
	adc_gpio.GPIO_Pin = GPIO_Pin_12;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);  // enable clock
	NVIC_EnableIRQ(ADC_IRQn); // enable irq
	GPIO_Init(GPIOC,&adc_gpio);
	adc_init.ADC_ContinuousConvMode = ENABLE;
	adc_init.ADC_Resolution =  ADC_Resolution_12b;
	adc_init.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADC1, &adc_init);
	ADC_TempSensorVrefintCmd(ENABLE);
	//adc_common.ADC_Prescaler = ADC_Prescaler_Div8;
	//adc_common.ADC_Mode = ADC_DMAAccessMode_Disabled;
  //adc_common.ADC_TwoSamplingDelay	= ADC_TwoSamplingDelay_20Cycles;
	//ADC1->SQR1=0;
	//ADC1->SQR2=0;
	ADC1->SQR3=16;
	//ADC_CommonInit(&adc_common);
	ADC1->CR1|=ADC_CR1_EOCIE;
	ADC_RegularChannelConfig(ADC1, ADC_Channel_TempSensor, 1, ADC_SampleTime_480Cycles);
	ADC_Cmd(ADC1, ENABLE);
	ADC1->CR2|=ADC_CR2_SWSTART;
}


