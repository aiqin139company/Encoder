#ifndef _DMA_H_
#define _DMA_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f4xx.h"

void DMA1_CH7_Init(u32 cpar);
void DMA1_CH7_START(u32 cmar,u16 cndtr);
		
#ifdef __cplusplus
}	
#endif
#endif

