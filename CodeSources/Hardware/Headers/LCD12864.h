/**************************************************************
	文件名：LCD12864.h
	描述:LCD12864液晶屏相关函数
***************************************************************/
#ifndef _LCD12864_H_
#define _LCD12864_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "BSP.h"

/*引脚定义*/
#define LCD_RS  	PAOut(1)
#define LCD_RW  	PAOut(2)
#define LCD_EN  	PAOut(3)

#define DataPortOut(x) 				\
{															\
	GPIOA->MODER &= ~(0xffff);	\
	GPIOA->MODER |=   0x5555;		\
	GPIOA->ODR = (GPIOA->ODR&~(0xff<<0))|((x&0xff)<<0); \
	GPIOA->MODER &= ~(0xffff);	\
} 
		
#define DataPortIn()	  ( GPIOA->IDR&(0xff<<0) )
		
		
/*函数声明*/
u8 Lcd_Check_Busy(void);				//查忙函数
void Lcd_Write_Com(u8 dat);			//写命令函数
void Lcd_Write_Data(u8 dat);		//写数据函数
void Lcd_Clear(void);						//清屏函数
void Lcd_Write_String(u8 x,u8 y,u8 *s);	//写字符串函数
void Lcd_GPIO_Init(void);				//引脚初始化函数
void Lcd_Init(void);						//初始化函数
 
#ifdef __cplusplus
}
#endif	
#endif /* _LCD12864_H_ */

