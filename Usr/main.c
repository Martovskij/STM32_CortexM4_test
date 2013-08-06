#include "main.h"



int main(void)
{
	
	gpioInit();
	__enable_irq();
	DacInit();
	DacWrite(0x0A,1);
	
	for(;;)
	{
		
	}

	return 0;
}

