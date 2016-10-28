#include "EncoderUI.h"


///Show
int EncoderUI::Show()
{
	return Show(selVal);
}

///Show
int EncoderUI::Show(int operation)
{
	selVal = operation;
	bsp->ClearLcd();
	bsp->WriteLcd(selVal,2,(u8*)"*");
	bsp->WriteLcd(0,4,(u8*)"捕获测试");
	bsp->WriteLcd(1,4,(u8*)"计算脉冲");
	bsp->WriteLcd(2,4,(u8*)"相位偏差");
	bsp->WriteLcd(3,0,(u8*)"确定");
	bsp->WriteLcd(3,12,(u8*)"取消");
	return 0;
}



