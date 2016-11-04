#ifndef _PWM_H_
#define _PWM_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "BSP.h"

void Pwm_Init(u16 psc, u16 arr);
void Pwm_Set(u16 psc, u16 arr, u16 ccr);		
		
#ifdef __cplusplus
}
#endif
#endif /* _PWM_H_ */

