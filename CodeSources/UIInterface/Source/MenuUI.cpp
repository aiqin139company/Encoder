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
	bsp->WriteLcd(0,4,(u8*)"��������");
	bsp->WriteLcd(1,4,(u8*)"���õ��");
	bsp->WriteLcd(2,4,(u8*)"���ò���");
	bsp->WriteLcd(3,0,(u8*)"ȷ��");
	bsp->WriteLcd(3,12,(u8*)"ȡ��");
	return 0;
}

