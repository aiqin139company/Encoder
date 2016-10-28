#ifndef _ENCODER_H_
#define _ENCODER_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f4xx.h"
#include "GpiosConfig.h"
	 
#define ENCODER_DIR			( (TIM2->CR1&(1<<4)) ? 1 : 0 ) 
#define ENCODER_COUNT		( TIM2->CNT )	 
	 
void Encoder_Init(u32 encoderLines);
void SetEncoderLines(u32 encoderLines);
	 
#ifdef __cplusplus
}
#endif
#endif

