#ifndef _BSP_H_
#define _BSP_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "Adc.h"
#include "I2c.h"
#include "Pwm.h"
#include "Uart.h"
#include "Eeprom.h"
#include "Encoder.h"
#include "GpiosConfig.h"

/*
	 Function: BSP Initialize
*/	 
inline void BSP_Init(void)
{
	SysTick->CTRL &= ~(1<<2);			//Select systick clock source: SYSCLK_MHZ/8 = 64/8 = 8M (document: PM0214) 
}


/*
	Function: delay (x) ms  
	Delay range: 0-1864 ms
*/
inline void Delay_ms(u32 timer)
{
	u32 temp;
	SysTick->LOAD = 8000 * timer;	//1 ms = 8000 clocks
	SysTick->VAL  = 0x0;					//Clear VAL
	SysTick->CTRL |= 1<<0;				//Enable Systick
	do{
		temp = SysTick->CTRL;
	}while((temp & 1<<16)==0);		//Waiting for delay time out
	SysTick->CTRL &= ~(1<<0);			//Disable Systick
}


/*
	Function: delay (x) us
	Delay range: 0-1864135
*/
inline void Delay_us(u32 timer)
{
	u32 temp;
	SysTick->LOAD = 8 * timer;		//1 us = 8 clocks
	SysTick->VAL  = 0x0;					//Clear VAL
	SysTick->CTRL |= 1<<0;				//Enable Systick 
	do{
		temp = SysTick->CTRL;
	}while((temp & 1<<16)==0);		//waiting for delay time out  
	SysTick->CTRL &= ~(1<<0);			//Disable Systick
}


#ifdef __cplusplus
}
#endif	 
#endif

