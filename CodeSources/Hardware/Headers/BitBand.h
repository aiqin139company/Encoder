#ifndef __BITBAND_H__
#define __BITBAND_H__

#ifdef __cpluspuls
	extern "C" {
#endif

#include "stm32f4xx.h"

/* �������궨�� bitband macro ------------------------------------------------*/
/* ʹ��bitband����������bit�����ĳ����Ч�ʣ�����GPIO�ܽŵĿ���Ч����Ϊ���� */
/* ��������� ��32MB����������ķ���ӳ��Ϊ��1MB ����bit-band���ķ���(ʵ�ʴ�С����оƬ�й�) */
#define Periph_BASE         0x40000000  // �������ַ Peripheral 
#define Periph_BB_BASE      0x42000000  // �������������ַ Peripheral bitband

/* ע�⣺���볣������ʱ���ڱ���ʱ��������������������ַ�������ܴﵽ����Ч�ʵ�Ŀ��(�Ƽ�)
         ����������������ֻ��������ʱ��STM32�Լ������������ַ��Ч�ʻ����ۿ�(���Ƽ�) */
#define Periph_BB(PeriphAddr, BitNumber)    \
          *(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2))
	 
#define Periph_ResetBit_BB(PeriphAddr, BitNumber)    \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2)) = 0)
   
#define Periph_SetBit_BB(PeriphAddr, BitNumber)       \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2)) = 1)

#define Periph_GetBit_BB(PeriphAddr, BitNumber)       \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((BitNumber) << 2)))

/* ����GPIO����������������壬nΪbitλ�÷�ΧΪ0��15    */
/* ���Ƕ�GPIOA.15����������Ҫ��ʼ��GPIO��Ȼ��ʹ�÷����� */
/* ��GPIOA.15����͵�ƽ��   PAOutBit(15) = 0;           */
/* ��GPIOA.15����͵�ƽ��   PAOutBit(15) = 1;           */
/* ��ȡGPIOA.15����ĵ�ƽ�� data = PAInBit(15);         */
#define PAOutBit(n)     Periph_BB((uint32_t)&GPIOA->IDR,n)  //��� 
#define PASetBit(n)     (PAOutBit(n) = 1)                   //��� ��
#define PAResetBit(n)   (PAOutBit(n) = 0)                   //��� ��
#define PAInBit(n)      Periph_BB((uint32_t)&GPIOA->IDR,n)  //���� 

#define PBOutBit(n)     Periph_BB((uint32_t)&GPIOB->ODR,n)  //��� 
#define PBSetBit(n)     (PBOutBit(n) = 1)                   //��� ��
#define PBResetBit(n)   (PBOutBit(n) = 0)                   //��� ��
#define PBInBit(n)      Periph_BB((uint32_t)&GPIOB->IDR,n)  //���� 

#define PCOutBit(n)     Periph_BB((uint32_t)&GPIOC->ODR,n)  //��� 
#define PCSetBit(n)     (PCOutBit(n) = 1)                   //��� ��
#define PCResetBit(n)   (PCOutBit(n) = 0)                   //��� ��
#define PCInBit(n)      Periph_BB((uint32_t)&GPIOC->IDR,n)  //���� 

#define PDOutBit(n)     Periph_BB((uint32_t)&GPIOD->ODR,n)  //��� 
#define PDSetBit(n)     (PDOutBit(n) = 1)                   //��� ��
#define PDResetBit(n)   (PDOutBit(n) = 0)                   //��� ��
#define PDInBit(n)      Periph_BB((uint32_t)&GPIOD->IDR,n)  //���� 

#define PEOutBit(n)     Periph_BB((uint32_t)&GPIOE->ODR,n)  //��� 
#define PESetBit(n)     (PEOutBit(n) = 1)                   //��� ��
#define PEResetBit(n)   (PEOutBit(n) = 0)                   //��� ��
#define PEInBit(n)      Periph_BB((uint32_t)&GPIOE->IDR,n)  //����

#define PFOutBit(n)     Periph_BB((uint32_t)&GPIOF->ODR,n)  //��� 
#define PFSetBit(n)     (PFOutBit(n) = 1)                   //��� ��
#define PFResetBit(n)   (PFOutBit(n) = 0)                   //��� ��
#define PFInBit(n)      Periph_BB((uint32_t)&GPIOF->IDR,n)  //����

#define PGOutBit(n)     Periph_BB((uint32_t)&GPIOG->ODR,n)  //��� 
#define PGSetBit(n)     (PGOutBit(n) = 1)                   //��� ��
#define PGResetBit(n)   (PGOutBit(n) = 0)                   //��� ��
#define PGInBit(n)      Periph_BB((uint32_t)&GPIOG->IDR,n)  //����


#ifdef __cpluspuls
}
#endif

#endif /* __BITBAND_H__ */


