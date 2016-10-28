#ifndef _ADC_H_
#define _ADC_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h" 	 
#include "GpiosConfig.h"
	 
#define VM_ADC_RES	 	ADC2->DR
#define V_ADC_RES			ADC3->DR
#define U_ADC_RES			ADC4->DR
	 
void Adc_Init(void);
void Adc_Configure(ADC_TypeDef* ADCx, uint8_t ADC_Channel);	 
void AdcStartConversion(void);
void AdcWaitEoc(void);
void AdcChargeTrigger(ADC_TypeDef* ADCx, uint16_t ADC_ExternalTrigEventEdge);
void Adc_ExternalTrigger(FunctionalState NewState);	 
	 
#ifdef __cplusplus
}
#endif	 
#endif

