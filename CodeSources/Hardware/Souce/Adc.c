#include "Adc.h"

/*
	Function: Adc Initialize
	Depiction: VM is ADC2
						 VISO is ADC3
						 UISO is ADC4
*/
void Adc_Init(void)
{
	/* Init ADC Pin */
	Adc_Pin_Init();
	
	/* Enable ADC1_2 and ADC3_4 clock */
	RCC_ADCCLKConfig(RCC_ADC12PLLCLK_Div2);
	RCC_ADCCLKConfig(RCC_ADC34PLLCLK_Div2);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC12, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC34, ENABLE);
	
	/* Configure ADC and Setting sample Channel */
	Adc_Configure(ADC4,ADC_Channel_3);			//UISO
	Adc_Configure(ADC3,ADC_Channel_1);			//VISO
	Adc_Configure(ADC2,ADC_Channel_1);			//VM
	
	/* ADC interrupt configure */
	ADC_ITConfig(ADC2,ADC_IT_EOC,ENABLE);
	Set_NVIC(ADC1_2_IRQn,2,1);	
} 


/*
	Function:Adc_Configure
*/
void Adc_Configure(ADC_TypeDef* ADCx, uint8_t ADC_Channel)
{
	/* Calibration procedure */
	ADC_VoltageRegulatorCmd(ADCx, ENABLE);
	ADC_SelectCalibrationMode(ADCx, ADC_CalibrationMode_Single);
	ADC_StartCalibration(ADCx);
	while(ADC_GetCalibrationStatus(ADCx) != RESET){}
	
	/* Common Configuration */
	ADC_CommonInitTypeDef ADC_CommonInitStructure;	
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Clock = ADC_Clock_AsynClkMode;
	ADC_CommonInit(ADCx, &ADC_CommonInitStructure);
	
	/* Advanced Configuration */
	ADC_InitTypeDef ADC_InitStructure;
	ADC_StructInit(&ADC_InitStructure);	
	ADC_InitStructure.ADC_ContinuousConvMode = ADC_ContinuousConvMode_Disable;
	ADC_InitStructure.ADC_ExternalTrigConvEvent = ADC_ExternalTrigConvEvent_9;
	ADC_InitStructure.ADC_ExternalTrigEventEdge =	ADC_ExternalTrigEventEdge_RisingEdge;
	ADC_Init(ADCx, &ADC_InitStructure); 
	
	/* ADC regular channel1 Configuration */
	ADC_RegularChannelConfig(ADCx, ADC_Channel, 1, ADC_SampleTime_7Cycles5);
		
	/* Enable ADC */
	ADC_Cmd(ADCx, ENABLE);

	/* Wait for ADRDY */
	while(!ADC_GetFlagStatus(ADCx, ADC_FLAG_RDY)){}
		
	/* Start ADC Software Conversion */ 
	ADC_StartConversion(ADCx);
}


/*
	Function: Software Trigger Conversion
*/
void AdcStartConversion(void)
{
	ADC_StartConversion(ADC4);
	ADC_StartConversion(ADC3);
	ADC_StartConversion(ADC2);
}


/*
	Function: Waiting Convereted
*/
void AdcWaitEoc(void)
{
	while(!ADC_GetFlagStatus(ADC2, ADC_FLAG_EOC)){}
	while(!ADC_GetFlagStatus(ADC3, ADC_FLAG_EOC)){}
	while(!ADC_GetFlagStatus(ADC4, ADC_FLAG_EOC)){}
}


/*
	Function: Change single Adc trigger
*/
void AdcChargeTrigger(ADC_TypeDef* ADCx, uint16_t ADC_ExternalTrigEventEdge)
{
	ADC_StopConversion(ADCx);
	ADC_ExternalTriggerConfig(ADCx,ADC_ExternalTrigConvEvent_9,ADC_ExternalTrigEventEdge);

	/* wait for ADRDY */
	while(!ADC_GetFlagStatus(ADCx, ADC_FLAG_RDY)){}	
}


/*
	Function: Change AdcTrigger
*/
void Adc_ExternalTrigger(FunctionalState NewState)
{
	if ( NewState != DISABLE )
	{
		AdcChargeTrigger(ADC4, ADC_ExternalTrigEventEdge_RisingEdge);
		AdcChargeTrigger(ADC3, ADC_ExternalTrigEventEdge_RisingEdge);
		AdcChargeTrigger(ADC2, ADC_ExternalTrigEventEdge_RisingEdge);
	}
	else
	{
		AdcChargeTrigger(ADC4, ADC_ExternalTrigEventEdge_None);
		AdcChargeTrigger(ADC3, ADC_ExternalTrigEventEdge_None);
		AdcChargeTrigger(ADC2, ADC_ExternalTrigEventEdge_None);
	}
}

