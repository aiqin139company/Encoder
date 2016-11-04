#include "Lcd12864.h"

/**************************************************************
	函数功能：查忙模式 由于开发板的问题，无法查忙，所以更改成延时
***************************************************************/
u8 Lcd_Check_Busy(void)
{
	DataPortOut(0xff);				//输出高电阻
	LCD_RS = 0;								//复位
	LCD_RW = 1;								//读模式
	LCD_EN = 0;								//清除使能
	LCD_EN = 1;								//使能
	return (DataPortIn() & 0x80);	//读出最高位 忙位
}

//u8 Lcd_Check_Busy(void)
//{
//	Delay_us(20);
//	return 1;
//}

/**************************************************************
	函数功能：写入命令函数
***************************************************************/
void Lcd_Write_Com(u8 dat)
{
	while(Lcd_Check_Busy());			//查忙
	LCD_RS = 0;										//写命令
	LCD_RW = 0;										//写模式
	LCD_EN = 1;										//使能
	DataPortOut(dat);							//写入命令	
	LCD_EN = 0;										//清除使能
}

/**************************************************************
	函数功能：写入数据函数
***************************************************************/
void Lcd_Write_Data(u8 dat)
{
	while(Lcd_Check_Busy());			//查忙
	LCD_RS = 1;										//写数据
	LCD_RW = 0;										//写模式
	LCD_EN = 1;										//使能
	DataPortOut(dat);							//写入数据
	LCD_EN = 0;										//清除使能
}

/**************************************************************
	函数功能：清屏函数
***************************************************************/
void Lcd_Clear(void)
{
	Lcd_Write_Com(0x01);			//写命令 0x01 清屏指令
	Delay_ms(5);							//等待
}

/**************************************************************
	函数功能：写入字符串函数
	参数：x：位置 y: 行数 *s：显示的字符串
***************************************************************/
void Lcd_Write_String(u8 x,u8 y,u8 *s)
{
	if(y == 0) Lcd_Write_Com(0x80 + x);   //第一行位置
	if(y == 1) Lcd_Write_Com(0x90 + x);		//第二行位置
	if(y == 2) Lcd_Write_Com(0x88 + x);		//第三行位置
	if(y == 3) Lcd_Write_Com(0x98 + x);		//第四行位置
	
	while( *s )
	{														
		Lcd_Write_Data(*s);									//写入数据，Lcd内部自动地址加1
		s++;																//字符串推后1位字节
	}
}

/**************************************************************
	函数功能：Lcd12864引脚初始化函数
***************************************************************/
void Lcd_GPIO_Init(void)
{
	/* Enable GPIOC clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	/* Configue the Enable pin */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Set Bit */
	GPIO_SetBits(GPIOA,GPIO_Pin_All);
}

/**************************************************************
	函数功能：Lcd12864初始化函数
***************************************************************/
void Lcd_Init(void) 
{
	Lcd_GPIO_Init();				//相关引脚初始化
	Lcd_Write_Com(0x38);		//显示模式设置 
	Delay_ms(20);
	Lcd_Write_Com(0x08);    //显示关闭 
	Lcd_Write_Com(0x01);    //显示清屏 
	Lcd_Write_Com(0x06);    //显示光标移动设置 
	Delay_ms(5); 
	Lcd_Write_Com(0x0C);    //显示开及光标设置
}


