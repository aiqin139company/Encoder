#ifndef __BIT_BAND_H__
#define __BIT_BAND_H__

#ifdef __cpluspuls
	extern "C" {
#endif

#include "stm32f4xx.h"

/* �������궨�� band macro ------------------------------------------------*/
/* ʹ��band���������Ʋ����ĳ����Ч�ʣ�����GPIO�ܽŵĿ���Ч����Ϊ���� */
/* ��������� ��32MB����������ķ���ӳ��Ϊ��1MB ����-band���ķ���(ʵ�ʴ�С����оƬ�й�) */
#define Periph_BASE         0x40000000  // �������ַ Peripheral 
#define Periph_BB_BASE      0x42000000  // �������������ַ Peripheral band

/* ע�⣺���볣������ʱ���ڱ���ʱ��������������������ַ�������ܴﵽ����Ч�ʵ�Ŀ��(�Ƽ�)
         ����������������ֻ��������ʱ��STM32�Լ������������ַ��Ч�ʻ����ۿ�(���Ƽ�) */
#define Periph_BB(PeriphAddr, Number)   		  \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)))
	 
#define Periph_Reset_BB(PeriphAddr, Number)   \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)) = 0)
   
#define Periph_Set_BB(PeriphAddr, Number)     \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)) = 1)

#define Periph_Get_BB(PeriphAddr, Number)     \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)))

/* ����GPIO����������������壬nΪλ�÷�ΧΪ0��15    */
/* ���Ƕ�GPIOA.15����������Ҫ��ʼ��GPIO��Ȼ��ʹ�÷����� */
/* ��GPIOA.15����͵�ƽ��   PAOut(15) = 0;           */
/* ��GPIOA.15����͵�ƽ��   PAOut(15) = 1;           */
/* ��ȡGPIOA.15����ĵ�ƽ�� data = PAIn(15);         */
#define PAOut(n)     Periph_BB((uint32_t)&GPIOA->IDR,n)  //��� 
#define PASet(n)     (PAOut(n) = 1)                  		 //��� ��
#define PAReset(n)   (PAOut(n) = 0)                  		 //��� ��
#define PAIn(n)      Periph_BB((uint32_t)&GPIOA->IDR,n)  //���� 

#define PBOut(n)     Periph_BB((uint32_t)&GPIOB->ODR,n)  //��� 
#define PBSet(n)     (PBOut(n) = 1)                 		 //��� ��
#define PBReset(n)   (PBOut(n) = 0)                		   //��� ��
#define PBIn(n)      Periph_BB((uint32_t)&GPIOB->IDR,n)  //���� 

#define PCOut(n)     Periph_BB((uint32_t)&GPIOC->ODR,n)  //��� 
#define PCSet(n)     (PCOut(n) = 1)                  	 	 //��� ��
#define PCReset(n)   (PCOut(n) = 0)                   	 //��� ��
#define PCIn(n)      Periph_BB((uint32_t)&GPIOC->IDR,n)  //���� 

#define PDOut(n)     Periph_BB((uint32_t)&GPIOD->ODR,n)  //��� 
#define PDSet(n)     (PDOut(n) = 1)                   	 //��� ��
#define PDReset(n)   (PDOut(n) = 0)                 	   //��� ��
#define PDIn(n)      Periph_BB((uint32_t)&GPIOD->IDR,n)  //���� 

#define PEOut(n)     Periph_BB((uint32_t)&GPIOE->ODR,n)  //��� 
#define PESet(n)     (PEOut(n) = 1)                 	   //��� ��
#define PEReset(n)   (PEOut(n) = 0)                 	   //��� ��
#define PEIn(n)      Periph_BB((uint32_t)&GPIOE->IDR,n)  //����

#define PFOut(n)     Periph_BB((uint32_t)&GPIOF->ODR,n)  //��� 
#define PFSet(n)     (PFOut(n) = 1)               	     //��� ��
#define PFReset(n)   (PFOut(n) = 0)               	     //��� ��
#define PFIn(n)      Periph_BB((uint32_t)&GPIOF->IDR,n)  //����

#define PGOut(n)     Periph_BB((uint32_t)&GPIOG->ODR,n)  //��� 
#define PGSet(n)     (PGOut(n) = 1)                 	   //��� ��
#define PGReset(n)   (PGOut(n) = 0)                		   //��� ��
#define PGIn(n)      Periph_BB((uint32_t)&GPIOG->IDR,n)  //����


#ifdef __cpluspuls
}
#endif

#endif /* __BIT_BAND_H__ */


