#include "BSPManager.h"

BSPManager BSPManager::instance = BSPManager();

BSPManager* BSPManager::Instance()
{
	return &instance;
}


///BSP Init
void BSPManager::BSP_Init()
{
	Delay_Init();
	KEY_Init();
	LED_Init();
	LCD_Init();
	UART_Init();
	ENCODER_Init();
	PWM_Init();
}


///KEY Init
void BSPManager::KEY_Init()
{
	Key_Init();
}


///LED Init
void BSPManager::LED_Init()
{
	Led_Init();
}


///LCD Init
void BSPManager::LCD_Init()
{
	Lcd_Init();
}


///UART Init
void BSPManager::UART_Init()
{
	Uart_Init(230400);
}


///Encoder Init
void BSPManager::ENCODER_Init()
{

}


///PWM Init
void BSPManager::PWM_Init()
{
	Pwm_Init(10,168);		//100khz
}


///Delay us
void BSPManager::Delay_US(u32 timer)
{
	Delay_us(timer);
}


///Delay ms
void BSPManager::Delay_MS(u32 timer)
{
	Delay_ms(timer);
}


///Read Key
int BSPManager::ReadKey(u8 mode)
{
	return Key_Scan(mode);
}


///Write Led
int BSPManager::WriteLed(u8 LedStatus)
{

	return 0;
}


///Clear Lcd
int BSPManager::ClearLcd()
{
	Lcd_Clear();
	return 0;
}


///Write Lcd
int BSPManager::WriteLcd(u8 x, u8 y, u8 *data)
{
	Lcd_Write_String(x,y,data);
	return 0;
}
	

///Read Uart
int BSPManager::ReadUart(u8 size, u8 *data)
{

	return 0;
}


///Write Uart
int BSPManager::WriteUart(u8 size, u8 *data)
{

	return 0;
}


///Read Encoder
int BSPManager::ReadEncoder()
{

	return 0;
}


///Write PWM
int BSPManager::WritePWM(u16 psc, u16 arr, u16 comp)
{
	Pwm_Set(psc,arr,comp);
	return 0;
}


