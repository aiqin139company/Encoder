#ifndef _UART_H_
#define _UART_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h" 
#include "stdio.h"	 
	 
void Uart_Init(u32 baudrate);
int UartRead(u8 *read);
int UartWrite(u16 num, u8 *p);	 
	 
#ifdef __cplusplus
}
#endif
#endif

