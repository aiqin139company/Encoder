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
	bsp->WriteLcd(1,6,(u8*)"����");
	bsp->WriteLcd(2,6,(u8*)"����");
	bsp->WriteLcd(3,0,(u8*)"ȷ��");
	bsp->WriteLcd(3,12,(u8*)"ȡ��");
	
	return 0;
}

