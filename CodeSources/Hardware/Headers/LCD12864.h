/**************************************************************
	�ļ�����LCD12864.h
	����:LCD12864Һ������غ���
***************************************************************/
#ifndef _LCD12864_H_
#define _LCD12864_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "BSP.h"

/*���Ŷ���*/
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
		
		
/*��������*/
u8 Lcd_Check_Busy(void);				//��æ����
void Lcd_Write_Com(u8 dat);			//д�����
void Lcd_Write_Data(u8 dat);		//д���ݺ���
void Lcd_Clear(void);						//��������
void Lcd_Write_String(u8 x,u8 y,u8 *s);	//д�ַ�������
void Lcd_GPIO_Init(void);				//���ų�ʼ������
void Lcd_Init(void);						//��ʼ������
 
#ifdef __cplusplus
}
#endif	
#endif /* _LCD12864_H_ */

