#include "Eeprom.h"

const u8 WriteCycleTime = 5;
const u8 WriteMode = 0xfe;
const u8 ReadMode = 0x01;

///eeprom initialize
void Eeprom_Init(void)
{
	//Eeprom Pin Init
	Eeprom_Pin_Init();
	
	//I2c initialize
	I2c_Init();
}

///read an number of data from eeprom
u8 EepromRead(u16 addr, u16 num, u8 *p)
{
	//send start condition
	I2cStart();			
	
	//send device address (write mode)
	I2cWriteByte(EEPROM_ADDR & WriteMode);	
	if( I2cGetAck() )	
	{
		I2cStop(); 
		return 4; 
	}

	//send device internal address
	I2cWriteByte(addr);		
	if( I2cGetAck() )			
	{
		I2cStop(); 
		return 5; 
	}
	//above is dummy write
	
	//send start condition
	I2cStart();	
	
	//send device address (read mode)
	I2cWriteByte(EEPROM_ADDR | ReadMode);
	if( I2cGetAck() )	
	{
		I2cStop();
		return 6; 
	}
	
	//read data
	for( u16 i = 0; i < num; i++ )		
	{
		*p = I2cReadByte();
		p ++;
		if ( i != (num - 1) )
			I2cPutAck(0);		//put ack
		else
			I2cPutAck(1);		//put nack
	}

	//send stop condition
	I2cStop(); 
	return 0;
	
}


///Write an number of date to eeprom
u8 EepromWrite(u16 addr, u16 num, u8 *p)
{
	u8 lessAddrNum;
	u8 reWrite = 1;
	
	do{
		//Calculates the remaining number of
		//bytes stored in this page for use
		lessAddrNum = EEPROM_PAGE_NUM - addr % EEPROM_PAGE_NUM;
		
		//This page will be able to
		//write the data to be written
		if( num <= lessAddrNum ) 
			lessAddrNum=num;
		
		//send start condition	
		I2cStart();	
		
		//send device address (write mode)
		I2cWriteByte(EEPROM_ADDR & WriteMode);	
		if( I2cGetAck() )  
		{
			I2cStop();				
			return 1;  
		}
		
		//send device internal address
		I2cWriteByte(addr);	
		if( I2cGetAck() ) 	
		{
			I2cStop();		
			return 2;  
		}
		
		//write data to eeprom
		for( u16 i = 0; i < lessAddrNum; i++ )
		{
			I2cWriteByte(*p);
			p++;
			if( I2cGetAck() ) 	
			{
				I2cStop();						
				return  3;  
			}
		}
		
		//Normal finish a page, send a stop condition, 
		//wait for the end of writing
		I2cStop();								
		Delay_ms(WriteCycleTime);	
		
		//Calculate how much data remains to writing
		if( num != lessAddrNum )
		{
			num = num - lessAddrNum;
			addr = addr + lessAddrNum;
		}
		else
			reWrite = 0;
	}
	while( reWrite );
	
	return 0;	
}

