#ifndef _CM4_SYSTEM_NVIC_H_
#define _CM4_SYSTEM_NVIC_H_
#include "stm32f4xx.h"

#ifdef __cplusplus
 extern "C" {
#endif

/* 中断总开关 */
#define DINT()      __set_PRIMASK(1)  
#define EINT()      __set_PRIMASK(0)  	 
	 
/* 设置中断优先级和分组 */
void Set_NVIC(IRQn_Type EXTIx_IRQn, u32 PreemptPriority, u32 SubPriority);

#ifdef __cplusplus
}
#endif		 
	 
#endif

