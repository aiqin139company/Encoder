#include "MenuUI.h"

///Show
int MenuUI::Show()
{
	return Show(selVal);
}

///Show
int MenuUI::Show(int operation)
{
	selVal = operation;
	bsp->ClearLcd();
	bsp->WriteLcd(selVal,4,(u8*)"*");
	bsp->WriteLcd(0,4,(u8*)"设置驱动");
	bsp->WriteLcd(1,4,(u8*)"设置电机");
	bsp->WriteLcd(2,4,(u8*)"设置测试");
	bsp->WriteLcd(3,0,(u8*)"确定");
	bsp->WriteLcd(3,12,(u8*)"取消");
	return 0;
}

