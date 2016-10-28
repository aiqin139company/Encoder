#include "SettingsUI.h"

///Show
int SettingsUI::Show()
{
	return Show(selVal);
}

///Home UI
int SettingsUI::Show(int operation)
{
	selVal = operation;
	bsp->ClearLcd();
	bsp->WriteLcd(selVal,4,(u8*)"*");
	bsp->WriteLcd(1,6,(u8*)"设置");
	bsp->WriteLcd(2,6,(u8*)"测试");
	bsp->WriteLcd(3,0,(u8*)"确定");
	bsp->WriteLcd(3,12,(u8*)"取消");
	
	return 0;
}

