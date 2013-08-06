#include "I2C.h"

static uint8_t rxData;
static uint8_t txData;
static uint8_t targetAddress;
/*
void i2cInit(void)
{

	I2C_InitTypeDef I2C_InitStruct;
  lowLevelInit();
	// configure I2C1
	I2C_InitStruct.I2C_ClockSpeed = 100000; 		// 100kHz
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;			// I2C mode
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;	// 50% duty cycle --> standard
	I2C_InitStruct.I2C_OwnAddress1 = 0x00;			// own address, not relevant in master mode
	I2C_InitStruct.I2C_Ack = I2C_Ack_Disable;		// disable acknowledge when reading (can be changed later on)
	
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; // set address length to 7 bit addresse
	I2C_Init(TARGET_I2C, &I2C_InitStruct);				// init I2C1
	//enable I2C1
	I2C_Cmd(TARGET_I2C, ENABLE);
	NVIC_EnableIRQ(I2C1_EV_IRQn); // enable irq
	I2C1->CR2 |=I2C_CR2_ITEVTEN;
}

void i2cWriteData(I2C_TypeDef* targetInterface, uint8_t address)
{
	targetAddress = address;
	I2C_GenerateSTART(targetInterface,ENABLE);
}




void i2cReadData()
{
	
}
static void lowLevelInit(void)
{
	 
	GPIO_InitTypeDef GPIO_InitStruct;
		// enable APB1 peripheral clock for I2C1
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	// enable clock for SCL and SDA pins
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_9; // we are going to use PB6 and PB7
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;			// set pins to alternate function
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		// set GPIO speed
	GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;			// set output to open drain --> the line has to be only pulled low, not driven high
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			// enable pull up resistors
	GPIO_Init(GPIOB, &GPIO_InitStruct);					// init GPIOB

	// Connect I2C1 pins to AF
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);	// SCL
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1); // SDA
	
}


*/





