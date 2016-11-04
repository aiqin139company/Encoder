#ifndef _BSP_MANAGER_H_
#define _BSP_MANAGER_H_

#include "BSP.h"

#define KEY_UP				0x01
#define KEY_DOWN			0x02
#define KEY_LEFT			0x03
#define KEY_RIGHT			0x04
#define KEY_CONFIRM 	0x05
#define KEY_CANCEL		0x06

#define LED_RED				0x01
#define LED_YOLLOW		0x02
#define LED_BLUE			0x04
#define LED_GREEN			0x08

#define KEY_SINGLE		0x00
#define KEY_MULTI			0x01

class BSPManager
{
private:

	void KEY_Init();
	void LED_Init();
	void LCD_Init();
	void UART_Init();
	void Encoder_Init();

	static BSPManager instance;

public:
	
	void BSP_Init();
	void Delay_US(u32 timer);
	void Delay_MS(u32 timer);
	int ReadKey(u8 mode);
	int WriteLed(u8 LedStatus);
	int ClearLcd();
	int WriteLcd(u8 x, u8 y, u8 *data);
	int ReadUart(u8 size, u8 *data);
	int WriteUart(u8 size, u8 *data);
	int ReadEncoder();

	static BSPManager* Instance();

};

#endif
