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
	bsp->WriteLcd(6,1,(u8*)"����");
	bsp->WriteLcd(6,2,(u8*)"����");
	bsp->WriteLcd(0,3,(u8*)"ȷ��");
	bsp->WriteLcd(12,3,(u8*)"ȡ��");
	
	return 0;
}

