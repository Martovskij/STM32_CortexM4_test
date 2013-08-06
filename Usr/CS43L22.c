#include "CS43L22.h"
#include "cpal.h"


static CPAL_TransferTypeDef dacRxStructure, dacTxStructure;
static I2C_InitTypeDef dacHwInitStruct;

uint8_t rxBuffer[BUFFER_SIZE], txBuffer[BUFFER_SIZE];

void DacInit()
{
       dacRxStructure.pbBuffer = rxBuffer;
	     dacRxStructure.wAddr1 = DAC_ADDR;
	     
	     dacTxStructure.pbBuffer = txBuffer;
	     dacTxStructure.wAddr1 = DAC_ADDR;
	
	     CPAL_I2C_StructInit(&I2C1_DevStructure);
       I2C1_DevStructure.CPAL_Mode = CPAL_MODE_MASTER;
	     
	     I2C1_DevStructure.wCPAL_Options =  CPAL_OPT_NO_MEM_ADDR;
	     I2C1_DevStructure.CPAL_ProgModel = CPAL_PROGMODEL_INTERRUPT;
	     I2C1_DevStructure.pCPAL_I2C_Struct->I2C_ClockSpeed = 100000;
	     I2C1_DevStructure.pCPAL_TransferRx = &dacRxStructure;
	     I2C1_DevStructure.pCPAL_TransferTx = &dacTxStructure;
	    
	     CPAL_I2C_Init(&I2C1_DevStructure);
}


void DacWrite(uint8_t targetAddr, uint8_t value)
{
     dacTxStructure.wAddr2 = targetAddr;
	   dacTxStructure.wNumData = 1;
	   txBuffer[0] = value;
	   if(CPAL_I2C_Write(&I2C1_DevStructure)!=CPAL_PASS)
		 {
			 
			 
		 }
	
	
}

void DacRead(uint8_t targetAddr)
{
	dacRxStructure.wAddr2 = targetAddr;
	dacRxStructure.wNumData = 1;
	
	if(CPAL_I2C_Read(&I2C1_DevStructure)!=CPAL_PASS)
	{
		
	}
	
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
