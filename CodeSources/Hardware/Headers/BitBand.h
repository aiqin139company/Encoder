#ifndef __BIT_BAND_H__
#define __BIT_BAND_H__

#ifdef __cpluspuls
	extern "C" {
#endif

#include "stm32f4xx.h"

/* 别名区宏定义 band macro ------------------------------------------------*/
/* 使用band可以提高设计操作的程序的效率，外设GPIO管脚的控制效果尤为明显 */
/* 外设别名区 对32MB外设别名区的访问映射为对1MB 外设-band区的访问(实际大小根据芯片有关) */
#define Periph_BASE         0x40000000  // 外设基地址 Peripheral 
#define Periph_BB_BASE      0x42000000  // 外设别名区基地址 Peripheral band

/* 注意：传入常量参数时，在编译时编译器会计算出别名区地址，这样能达到提升效率的目的(推荐)
         如果传入变量参数，只能在运行时由STM32自己计算别名区地址，效率会大打折扣(不推荐) */
#define Periph_BB(PeriphAddr, Number)   		  \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)))
	 
#define Periph_Reset_BB(PeriphAddr, Number)   \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)) = 0)
   
#define Periph_Set_BB(PeriphAddr, Number)     \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)) = 1)

#define Periph_Get_BB(PeriphAddr, Number)     \
          (*(__IO uint32_t *) (Periph_BB_BASE | ((PeriphAddr - Periph_BASE) << 5) | ((Number) << 2)))

/* 外设GPIO输入输出别名区定义，n为位置范围为0到15    */
/* 我们对GPIOA.15操作，首先要初始化GPIO，然后使用方法： */
/* 对GPIOA.15输出低电平：   PAOut(15) = 0;           */
/* 对GPIOA.15输出低电平：   PAOut(15) = 1;           */
/* 读取GPIOA.15输入的电平： data = PAIn(15);         */
#define PAOut(n)     Periph_BB((uint32_t)&GPIOA->IDR,n)  //输出 
#define PASet(n)     (PAOut(n) = 1)                  		 //输出 高
#define PAReset(n)   (PAOut(n) = 0)                  		 //输出 低
#define PAIn(n)      Periph_BB((uint32_t)&GPIOA->IDR,n)  //输入 

#define PBOut(n)     Periph_BB((uint32_t)&GPIOB->ODR,n)  //输出 
#define PBSet(n)     (PBOut(n) = 1)                 		 //输出 高
#define PBReset(n)   (PBOut(n) = 0)                		   //输出 低
#define PBIn(n)      Periph_BB((uint32_t)&GPIOB->IDR,n)  //输入 

#define PCOut(n)     Periph_BB((uint32_t)&GPIOC->ODR,n)  //输出 
#define PCSet(n)     (PCOut(n) = 1)                  	 	 //输出 高
#define PCReset(n)   (PCOut(n) = 0)                   	 //输出 低
#define PCIn(n)      Periph_BB((uint32_t)&GPIOC->IDR,n)  //输入 

#define PDOut(n)     Periph_BB((uint32_t)&GPIOD->ODR,n)  //输出 
#define PDSet(n)     (PDOut(n) = 1)                   	 //输出 高
#define PDReset(n)   (PDOut(n) = 0)                 	   //输出 低
#define PDIn(n)      Periph_BB((uint32_t)&GPIOD->IDR,n)  //输入 

#define PEOut(n)     Periph_BB((uint32_t)&GPIOE->ODR,n)  //输出 
#define PESet(n)     (PEOut(n) = 1)                 	   //输出 高
#define PEReset(n)   (PEOut(n) = 0)                 	   //输出 低
#define PEIn(n)      Periph_BB((uint32_t)&GPIOE->IDR,n)  //输入

#define PFOut(n)     Periph_BB((uint32_t)&GPIOF->ODR,n)  //输出 
#define PFSet(n)     (PFOut(n) = 1)               	     //输出 高
#define PFReset(n)   (PFOut(n) = 0)               	     //输出 低
#define PFIn(n)      Periph_BB((uint32_t)&GPIOF->IDR,n)  //输入

#define PGOut(n)     Periph_BB((uint32_t)&GPIOG->ODR,n)  //输出 
#define PGSet(n)     (PGOut(n) = 1)                 	   //输出 高
#define PGReset(n)   (PGOut(n) = 0)                		   //输出 低
#define PGIn(n)      Periph_BB((uint32_t)&GPIOG->IDR,n)  //输入


#ifdef __cpluspuls
}
#endif

#endif /* __BIT_BAND_H__ */


