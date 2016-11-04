#ifndef _I2C_H_
#define _I2C_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h" 	 
	 
void I2c_Init(void);
void I2cStart(void);
void I2cStop(void);
void I2cWriteByte(u8 data);	
u8 I2cReadByte(void);
u8 I2cGetAck(void);
void I2cPutAck(u8 ack);

#ifdef __cplusplus
}
#endif	 
#endif

