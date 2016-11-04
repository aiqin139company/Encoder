#ifndef _EEPROM_H_
#define _EEPROM_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h" 
#include "I2c.h"
#include "BSP.h"	 
	 
#define EEPROM_PAGE_NUM 	0x08   //AT24C02“≥¥Û–°
#define EEPROM_ADDR  			0xA0

void Eeprom_Init(void);
u8 EepromWrite(u16 addr, u16 num, u8 *p);
u8 EepromRead(u16 addr, u16 num, u8 *p);

#ifdef __cplusplus
}
#endif	 
#endif

