#include "Uart.h"

/*
	Function:	UART Pin Initialize
	Depiction: UART TX Pin is GPIOA_2
						 UART RX Pin is GPIOA_3
*/
void UART_Pin_Init(void)
{
	/* Enable GPIOA clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Config GPIOA and GPIOB as AFIO */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2,GPIO_AF_USART2);  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3,GPIO_AF_USART2); 
	
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
	Funtion: Uart Initialize
*/
void Uart_Init(u32 baudrate)
{
	/* Uart Pin initialize */
	UART_Pin_Init();
	
	/* Enable USART2 clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	/* Reset USART2 */
	USART_DeInit(USART2);
	
	/* Configure USART2 Clock */
	USART_ClockInitTypeDef USART_ClockInitStructure;
	USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
	USART_ClockInitStructure.USART_CPOL = USART_CPOL_High;
	USART_ClockInitStructure.USART_CPHA = USART_CPHA_1Edge;
	USART_ClockInitStructure.USART_LastBit = USART_LastBit_Enable;
	USART_ClockInit(USART2, &USART_ClockInitStructure);
	
	/* Configure USART2 format as 8N1 */
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = baudrate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl =
	USART_HardwareFlowControl_RTS_CTS;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART2, &USART_InitStructure);
	
	/* Enable USART2 */
	USART_Cmd(USART2, ENABLE);
}


//Gets data from USART2
int UartRead(u8 *read)
{
	if(USART2->SR & (1<<5))
	{
		*read = USART2->DR;
		return 0;
	}
	return 1;
}


//Send data by using USART2
int UartWrite(u16 num, u8 *p)
{
	while(num)
	{
		USART2->DR = p[num--];
		while(0==(USART2->SR&(1<<7)));	//waiting 
	}
	return num;
}


//fputc( printf )
int fputc(int c, FILE *file)
{
	USART_SendData(USART2, c);		//send data
	while(RESET==USART_GetFlagStatus(USART2, USART_FLAG_TXE));	//waiting 
	return c;											//return send data
}

