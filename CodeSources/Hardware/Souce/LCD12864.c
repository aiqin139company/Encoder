#include "Lcd12864.h"

/**************************************************************
	�������ܣ���æģʽ ���ڿ���������⣬�޷���æ�����Ը��ĳ���ʱ
***************************************************************/
u8 Lcd_Check_Busy(void)
{
	DataPortOut(0xff);				//����ߵ���
	LCD_RS = 0;								//��λ
	LCD_RW = 1;								//��ģʽ
	LCD_EN = 0;								//���ʹ��
	LCD_EN = 1;								//ʹ��
	return (DataPortIn() & 0x80);	//�������λ æλ
}

//u8 Lcd_Check_Busy(void)
//{
//	Delay_us(20);
//	return 1;
//}

/**************************************************************
	�������ܣ�д�������
***************************************************************/
void Lcd_Write_Com(u8 dat)
{
	while(Lcd_Check_Busy());			//��æ
	LCD_RS = 0;										//д����
	LCD_RW = 0;										//дģʽ
	LCD_EN = 1;										//ʹ��
	DataPortOut(dat);							//д������	
	LCD_EN = 0;										//���ʹ��
}

/**************************************************************
	�������ܣ�д�����ݺ���
***************************************************************/
void Lcd_Write_Data(u8 dat)
{
	while(Lcd_Check_Busy());			//��æ
	LCD_RS = 1;										//д����
	LCD_RW = 0;										//дģʽ
	LCD_EN = 1;										//ʹ��
	DataPortOut(dat);							//д������
	LCD_EN = 0;										//���ʹ��
}

/**************************************************************
	�������ܣ���������
***************************************************************/
void Lcd_Clear(void)
{
	Lcd_Write_Com(0x01);			//д���� 0x01 ����ָ��
	Delay_ms(5);							//�ȴ�
}

/**************************************************************
	�������ܣ�д���ַ�������
	������x��λ�� y: ���� *s����ʾ���ַ���
***************************************************************/
void Lcd_Write_String(u8 x,u8 y,u8 *s)
{
	if(y == 0) Lcd_Write_Com(0x80 + x);   //��һ��λ��
	if(y == 1) Lcd_Write_Com(0x90 + x);		//�ڶ���λ��
	if(y == 2) Lcd_Write_Com(0x88 + x);		//������λ��
	if(y == 3) Lcd_Write_Com(0x98 + x);		//������λ��
	
	while( *s )
	{														
		Lcd_Write_Data(*s);									//д�����ݣ�Lcd�ڲ��Զ���ַ��1
		s++;																//�ַ����ƺ�1λ�ֽ�
	}
}

/**************************************************************
	�������ܣ�Lcd12864���ų�ʼ������
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
	�������ܣ�Lcd12864��ʼ������
***************************************************************/
void Lcd_Init(void) 
{
	Lcd_GPIO_Init();				//������ų�ʼ��
	Lcd_Write_Com(0x38);		//��ʾģʽ���� 
	Delay_ms(20);
	Lcd_Write_Com(0x08);    //��ʾ�ر� 
	Lcd_Write_Com(0x01);    //��ʾ���� 
	Lcd_Write_Com(0x06);    //��ʾ����ƶ����� 
	Delay_ms(5); 
	Lcd_Write_Com(0x0C);    //��ʾ�����������
}


