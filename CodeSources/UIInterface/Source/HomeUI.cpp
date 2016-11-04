#include "HomeUI.h"

///Show
int HomeUI::Show()
{
	return Show(selVal);
}


///Home UI
int HomeUI::Show(int operation)
{
	selVal = operation;
	bsp->ClearLcd();
	bsp->WriteLcd(4,selVal+1,(u8*)"*");
	bsp->WriteLcd(6,1,(u8*)"设置");
	bsp->WriteLcd(6,2,(u8*)"测试");
	bsp->WriteLcd(0,3,(u8*)"确定");
	bsp->WriteLcd(12,3,(u8*)"取消");
	
	return 0;
}

