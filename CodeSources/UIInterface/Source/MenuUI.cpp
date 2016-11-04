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
	bsp->WriteLcd(4,0,(u8*)"��������");
	bsp->WriteLcd(4,1,(u8*)"���õ��");
	bsp->WriteLcd(4,2,(u8*)"���ò���");
	bsp->WriteLcd(0,3,(u8*)"ȷ��");
	bsp->WriteLcd(12,3,(u8*)"ȡ��");
	return 0;
}

