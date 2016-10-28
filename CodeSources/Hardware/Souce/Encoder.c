#include "Encoder.h"


/*
	Function: Encoder Initialize
*/
void Encoder_Init(u32 encoderLines)
{
	/* Encoder Pins Init */
	Encoder_Pin_Init();
	
	/* Enable TIM2 clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	/* Configure TIM2 Base Configuration */
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Period = encoderLines*4-1; 
	TIM_TimeBaseStructure.TIM_Prescaler = 0; 
	TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;    
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);              
	
	/* Configure Encoder */
	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12,
					TIM_ICPolarity_Rising ,TIM_ICPolarity_Rising);

	/* Enable TIM2 */
	TIM_Cmd(TIM2, ENABLE); 

}


/*
	Funtion: Setting Encoder Lines
*/
void SetEncoderLines(u32 encoderLines)
{
	TIM_Cmd(TIM2, DISABLE); 
	TIM2->ARR = encoderLines*4-1;
	TIM2->CNT = 0;
	TIM_Cmd(TIM2, ENABLE); 
}


