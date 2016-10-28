#ifndef _GPIOS_CONFIG_H_
#define _GPIOS_CONFIG_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h" 
#include "cm4_system_nvic.h"		 
	 
//ENABLE PIN
#define ENABLE_KEY 			( (GPIOC->IDR & 0x1<<13) ? 1 : 0 )	 
	 
//FAULT PINS
#define FAULT_LED(x)		( x ? (GPIOB->BSRR |= 0x01<<9) : (GPIOB->BRR |= 0x01<<9) )
#define FAULT_ALARM(x)	( x ? (GPIOC->BSRR |= 0x01<<14) : (GPIOC->BRR |= 0x01<<14) )

//HALL EFFECT SENSORS
#define HALL_U_PIN			( (GPIOA->IDR & 0x1<<6) ? 1 : 0 )
#define HALL_V_PIN			( (GPIOA->IDR & 0x1<<7) ? 1 : 0 )
#define HALL_W_PIN			( (GPIOB->IDR & 0x1<<0) ? 1 : 0 )
	
//OVERCURRENT PIN	
#define OC_PIN					( (GPIOB->IDR & 0x1<<13) ? 1 : 0 )	 
	 
//STEPCOUNTER PIN
#define STEP_DIR				( (GPIOB->IDR & 0x1<<14) ? 1 : 0 )
#define STEP_PUL				( (GPIOB->IDR & 0x1<<15) ? 1 : 0 )	 
#define STEP_EDGE(x)		{ 		\
	if ( x )										\
	{														\
		EXTI->RTSR |=  (1 << 15);	\
		EXTI->FTSR &= ~(1 << 15);	\
	}														\
	else												\
	{														\
		EXTI->RTSR &= ~(1 << 15);	\
		EXTI->FTSR |=  (1 << 15);	\
	}														\
}

//ADC PIN
//VM GPIOA_4
//Viso GPIOB_1
//Uiso GPIOB_12

//PWM PIN
//EPWM1 GPIOA_8
//EPWM2 GPIOA_9
//EPWM3 GPIOA_10

//UART PIN
//TX GPIOA_2
//RX GPIOA_3

//ENCODER PIN
//ENCODER_A GPIO_0
//ENCODER_B GPIO_1
#define ENCODER_Z_IN			( (EXTI->PR&(1<<6)) ? 1 : 0 )
#define ENCODER_Z_CL()		( EXTI->PR |= (1<<6) )	

//I2C PINS			
#define SCL(x)						( x ? (GPIOB->BSRR |= 0x01<<6) : (GPIOB->BRR |= 0x01<<6) )
#define SDA_OUT(x)				( x ? (GPIOB->BSRR |= 0x01<<7) : (GPIOB->BRR |= 0x01<<7) )
#define SDA_IN()  				( (GPIOB->IDR & 0x1<<7) ? 1 : 0 )	 

//EEPROM PIN
#define WP_ENABLE(x)			( x ? (GPIOB->BSRR |= 0x01<<5) : (GPIOB->BRR |= 0x01<<5) )

	 
//Functions
void Enable_Pin_Init(void);
void Fault_Pin_Init(void);
void Hall_Pin_Init(void);
void OverCurrent_Pin_Init(void);
void StepCounter_Pin_Init(void);
void Adc_Pin_Init(void);
void PWM_Pin_Init(void);
void UART_Pin_Init(void);
void Encoder_Pin_Init(void);
void I2c_Pin_Init(void);
void Eeprom_Pin_Init(void);

#ifdef __cplusplus
}
#endif
#endif

