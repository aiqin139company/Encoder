#ifndef _BSP_H_
#define _BSP_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include "BitBand.h"
#include "I2c.h"
#include "Uart.h"
#include "Eeprom.h"
#include "Key.h"
#include "LCD12864.h"
#include "Led.h"
#include "PWM.h"
	 
/*
	 Function: Delay Initialize
*/
void Delay_Init(void);
inline void Delay_Init(void)
{
	SysTick->CTRL &= ~(1<<2);			//Select systick clock source: SYSCLK_MHZ/8 = 168/8 = 21M (document: PM0214) 
}


/*
	Function: delay (x) ms  
	Delay range: 0-1864 ms
*/
void Delay_ms(u32 timer);
inline void Delay_ms(u32 timer)
{
	u32 temp;
	SysTick->LOAD = 21000 * timer;	//1 ms = 21000 clocks
	SysTick->VAL  = 0x0;						//Clear VAL
	SysTick->CTRL |= 1<<0;					//Enable Systick
	do{
		temp = SysTick->CTRL;
	}while((temp & 1<<16)==0);			//Waiting for delay time out
	SysTick->CTRL &= ~(1<<0);				//Disable Systick
}


/*
	Function: delay (x) us
	Delay range: 0-1864135
*/
void Delay_us(u32 timer);
inline void Delay_us(u32 timer)
{
	u32 temp;
	SysTick->LOAD = 21 * timer;		//1 us = 21 clocks
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

