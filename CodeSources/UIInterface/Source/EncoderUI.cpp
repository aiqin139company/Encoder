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
	bsp->WriteLcd(2,selVal,(u8*)"*");
	bsp->WriteLcd(4,0,(u8*)"�������");
	bsp->WriteLcd(4,1,(u8*)"��������");
	bsp->WriteLcd(4,2,(u8*)"��λƫ��");
	bsp->WriteLcd(0,3,(u8*)"ȷ��");
	bsp->WriteLcd(12,3,(u8*)"ȡ��");
	return 0;
}



