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
	bsp->WriteLcd(4,selVal,(u8*)"*");
	bsp->WriteLcd(4,0,(u8*)"设置驱动");
	bsp->WriteLcd(4,1,(u8*)"设置电机");
	bsp->WriteLcd(4,2,(u8*)"设置测试");
	bsp->WriteLcd(0,3,(u8*)"确定");
	bsp->WriteLcd(12,3,(u8*)"取消");
	return 0;
}

