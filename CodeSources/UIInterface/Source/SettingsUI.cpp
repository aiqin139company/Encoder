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
	bsp->WriteLcd(4,selVal,(u8*)"*");
	bsp->WriteLcd(6,1,(u8*)"����");
	bsp->WriteLcd(6,2,(u8*)"����");
	bsp->WriteLcd(0,3,(u8*)"ȷ��");
	bsp->WriteLcd(12,3,(u8*)"ȡ��");
	
	return 0;
}

