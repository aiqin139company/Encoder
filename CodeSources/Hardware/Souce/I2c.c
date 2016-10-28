#include "I2c.h"

void I2cDelay(void);

///iic init
void I2c_Init(void)
{
	//I2c Pin Init
	I2c_Pin_Init();
}


///iic delay
void I2cDelay(void)
{
	const u8 IICDELAY = 2;
	u8 timer = IICDELAY;
	while( timer-- ){}
}


///start condition
void I2cStart(void)
{
	SCL(0);
	SDA_OUT(1);
	
	SCL(1);
	I2cDelay();
	
	SDA_OUT(0);
	I2cDelay();
	
	SCL(0);
}


///stop condition
void I2cStop(void)
{
	SCL(0);
	SDA_OUT(0);
	
	SCL(1);
	I2cDelay();
	
	SDA_OUT(1);
}


///write one byte data
void I2cWriteByte(u8 data)
{ 
	const u8 MSB = 0x80;
	
	for( u8 i = 0; i < 8; i++ )
	{
		SCL(0);
		SDA_OUT(data & MSB);
		I2cDelay();
		
		SCL(1);
		data <<= 1;
		I2cDelay();
	}
	SCL(0);
}


///read one byte data
u8 I2cReadByte(void)
{
	u8 data = 0;
	
	SCL(0);
	SDA_OUT(1); 		//Switch to read mode
	
	for( u8 i = 0; i < 8; i++ )
	{
		SCL(0);
		I2cDelay();
		
		SCL(1);
		data <<= 1;
		if( SDA_IN() )
			data |= 0X01;	
		I2cDelay();
	}
	SCL(0);
	
	return  data;
}


///get ack, 0 : ack ,1 : nack
u8 I2cGetAck(void)
{
	u8 ack=0;
	
	SCL(0);
	SDA_OUT(1);			//Switch to read mode
	I2cDelay();
	
	SCL(1);
	if( SDA_IN() )
		ack = 1;
	I2cDelay();
	
	SCL(0);
	
	return ack;
}


///put ack, 0 : ack, 1 : nack
void I2cPutAck(u8 ack)
{
	SCL(0);
	SDA_OUT(ack);
	I2cDelay();
	
	SCL(1);
	I2cDelay();
	
	SCL(0);
}

