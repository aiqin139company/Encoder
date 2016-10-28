#include "BSPManager.h"

BSPManager BSPManager::instance = BSPManager();

BSPManager* BSPManager::Instance()
{
	return &instance;
}


///BSP Init
void BSPManager::BSP_Init()
{
	KEY_Init();
	LED_Init();
	LCD_Init();
	UART_Init();
	Encoder_Init();
}


///KEY Init
void BSPManager::KEY_Init()
{

}


///LED Init
void BSPManager::LED_Init()
{

}


///LCD Init
void BSPManager::LCD_Init()
{

}


///UART Init
void BSPManager::UART_Init()
{

}


///Encoder Init
void BSPManager::Encoder_Init()
{

}


///Delay us
void BSPManager::Delay_us(u32 timer)
{
	Delay_us(timer);
}


///Delay ms
void BSPManager::Delay_ms(u32 timer)
{
	Delay_ms(timer);
}


///Read Key
int BSPManager::ReadKey(u8 mode)
{

	return 0;
}


///Write Led
int BSPManager::WriteLed(u8 LedStatus)
{

	return 0;
}


///Write Lcd
int BSPManager::WriteLcd(u8 x, u8 y, u8 size, u8 *data)
{

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

	
