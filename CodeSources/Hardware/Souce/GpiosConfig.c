#include "GpiosConfig.h"

/*
	Function:	Enable Pin Initialize
	Depiction: Enable Pin is GPIOC_13
*/
void Enable_Pin_Init(void)
{
	/* Enable GPIOC clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	
	/* Configue the Enable pin */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	/* Set Bit */
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
}
	

/*
	Function: Fault led and alarm pin Initialize
	Depiction: Fault_Led pin is GPIOB_9
						 Fault_Alarm pin is GPIOC_14
*/
void Fault_Pin_Init(void)
{
	/* Enable GPIOs clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC, ENABLE);
	
	/* Configure ALARM_LED and ALARM_OUTPUT pin */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	/* Set bits */
	GPIO_SetBits(GPIOB,GPIO_Pin_9);
	GPIO_SetBits(GPIOC,GPIO_Pin_14);
}


/*
	Function:	Initializes the Hall effect sensors Pins
	Depiction: HALL_U_PIN is GPIOA_6
				  	 HALL_V_PIN is GPIOA_7
						 HALL_W_PIN is GPIOB_0
*/
void Hall_Pin_Init(void)
{
	/* Enable GPIOA and GPIOB clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB, ENABLE);
	
	/* Configure the GPIO bits used by the hall effect sensors */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* Reset bits */
	GPIO_ResetBits(GPIOA,GPIO_Pin_6|GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
}


/*
	Function:	OverCurrent Pin Initialize
	Depiction: OverCurrent Pin is GPIOB_13
						It`s interrupt
*/
void OverCurrent_Pin_Init(void)
{
	/* Enable GPIOB's AHB interface clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	
	/* Enable SYSCFG's APB interface clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	/* Configure PB13 pin in input mode */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* Connect EXTI Line13 to PB13 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource13);
	
	/* Configure EXTI line13 */
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line13;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/* Set NVIC */
	Set_NVIC(EXTI15_10_IRQn,1,1);
	
}


/*
	Function:	StepCounter Pin Initialize
	Depiction:StepCounter_dir Pin is GPIOB_14 
						StepCounter_pulse Pin is GPIOB_15
						It`s interrupt
*/
void StepCounter_Pin_Init(void)
{
	/* Enable GPIOB's AHB interface clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	
	/* Enable SYSCFG's APB interface clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	/* Configure PB14 and PB15 pin in input mode */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* Connect EXTI Line15 to PB15 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource15);
	
	/* Configure EXTI line15 */
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	/* Set NVIC */
	Set_NVIC(EXTI15_10_IRQn,1,1);
	
}


/*
	Function:	Adc Pin Initialize
	Depiction: VM Pin is GPIOA_4
						 Viso Pin is GPIOB_1
						 Uiso Pin is GPIOB_12
*/
void Adc_Pin_Init(void)
{
	/* Enable GPIOA and GPIOB clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB, ENABLE);
	
	/* Configure VM Viso Uiso pin */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_12;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


/*
	Function:	Pwm Pin Initialize
	Depiction: EPWM1 Pin is GPIOA_8
						 EPWM2 Pin is GPIOA_9
						 EPWM3 Pin is GPIOA_10
*/
void PWM_Pin_Init(void)
{
	/* Enable GPIOA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	
	/* Config AFIO */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8,GPIO_AF_6);  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9,GPIO_AF_6); 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10,GPIO_AF_6); 
	
	/* Config GPIOA 8 9 10 as General purpose output mode with pull up */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


/*
	Function:	UART Pin Initialize
	Depiction: UART TX Pin is GPIOA_2
						 UART RX Pin is GPIOA_3
*/
void UART_Pin_Init(void)
{
	/* Enable GPIOA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Config GPIOA and GPIOB as AFIO */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2,GPIO_AF_7);  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3,GPIO_AF_7); 
	
	/* Config GPIOA2(TX) in output */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Config GPIOA3(RX) in input */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


/*
	Function:	Encoder Pin Initialize
	Depiction: Encoder A Pin is GPIOA_0
						 Encoder B Pin is GPIOA_1
						 Encoder Z Pin is GPIOA_6 as interrupt (using Hall_U pin)
*/
void Encoder_Pin_Init(void)
{
	/* Enable GPIOA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	
	/* Config AFIO */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0,GPIO_AF_1);  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1,GPIO_AF_1); 
	
	/* Config GPIOA 0 1 as AF mode */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Config GPIOA_6 as input mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Reset bits */
	GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_6);
	
	/* Enable SYSCFG's APB interface clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	/* Connect EXTI Line6 to PB6 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource6);
	
	/* Configure EXTI line6 */
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line6;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
//	/* Set NVIC */
//	Set_NVIC(EXTI9_5_IRQn,1,1);
	
}


/*
	Function:	I2c Pin Initialize
	Depiction: I2c_Scl Pin is GPIOB_6
						 I2c_Sda Pin is GPIOB_7
*/
void I2c_Pin_Init(void)
{
	/* Enable GPIOB clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Config GPIOB6 as General purpose output mode with pull up(SCL) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* Config GPIOB7 as Output open-drain mode with pull up */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


/*
	Function:	Eeprom Pin Initialize
	Depiction: Eeprom_Wp Pin is GPIOB_5
*/
void Eeprom_Pin_Init(void)
{
	/* Enable GPIOB clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Config GPIOB5 as General purpose output mode with pull up */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


void HardFault_Handler(void)
{
  if (CoreDebug->DHCSR & 1) //check C_DEBUGEN == 1 -> Debugger Connected  
	{
      __breakpoint(0);  		// halt program execution here         
  }
  while (1)
  {
  }
}

