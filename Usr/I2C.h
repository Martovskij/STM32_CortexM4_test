#ifndef _I2C_H
#define _I2C_H

#include "main.h"


#define TARGET_I2C   I2C1
#define TX_EMPTY    0b000


void i2cInit(void);
static void lowLevelInit(void);
void I2C1_EV_IRQHandler(void);                                              
void I2C1_ER_IRQHandler(void);
void i2c_start(void);
void i2c_stop(void);


#endif



