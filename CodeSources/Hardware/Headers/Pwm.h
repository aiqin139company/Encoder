#ifndef _PWM_H_
#define _PWM_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h" 	 
#include "GpiosConfig.h"
	 
void Pwm_Init(u32 timerArr, u32 timerPsc);

///Set pwm params
inline void PwmSet(u16 u, u16 v, u16 w)
{
	TIM1->CCR1 = u;
	TIM1->CCR2 = v;
	TIM1->CCR3 = w;
}

///Disable pwm output
inline void PwmDisable(void)
{
	TIM_CtrlPWMOutputs(TIM1,DISABLE);
}

#ifdef __cplusplus
}
#endif	 
#endif

