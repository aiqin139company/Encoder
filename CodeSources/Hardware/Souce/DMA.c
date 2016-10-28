#include "DMA.h"

/*
DMA通道7初始化   --串口2发送
cpar：外设地址
*/
void DMA1_CH7_Init(u32 cpar)
{
	/*开启外设相关时钟*/
	 RCC->AHBENR|=1<<0;            //开启DMA1时钟
	 DMA1_Channel7->CPAR=(u32)cpar;//外设地址
	 DMA1_Channel7->CCR=0x0;       //寄存器清除
	 DMA1_Channel7->CCR|=0x0<<14;  //0：非存储器到存储器模式；1：启动存储器到存储器模式。
	 DMA1_Channel7->CCR|=0x3<<12;  //优先级设置   00：低  01：中  10：高  11：最高
	 DMA1_Channel7->CCR|=0x0<<10;  //存储器数据宽度设置 00： 8位 01： 16位 10： 32位
   DMA1_Channel7->CCR|=0x0<<8;   //外设数据宽度设置   00： 8位 01： 16位 10： 32位
   DMA1_Channel7->CCR|=0x1<<7;   //0：不执行存储器地址增量操作 1：执行存储器地址增量操作
   DMA1_Channel7->CCR|=0x0<<6;   //0：不执行外设地址增量操作   1：执行外设地址增量操作
   DMA1_Channel7->CCR|=0x0<<5;   //0：不执行循环操作           1：执行循环操作
	 DMA1_Channel7->CCR|=0x1<<4;   //0：从外设读                 1：从存储器读
}

/*
DMA1_CH7使能一次传输
cmar：存储器地址
cndtr：传输的数量
*/
void DMA1_CH7_START(u32 cmar,u16 cndtr)
{
	DMA1_Channel7->CCR&=~(1<<0); 				   //关闭DMA传输
	DMA1_Channel7->CMAR=(u32)cmar;				 //存储器地址
	DMA1_Channel7->CNDTR=cndtr;	 					 //传输的数量
	DMA1_Channel7->CCR|=1<<0; 				     //开启DMA传输
}

