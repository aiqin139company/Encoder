#include "DriverUI.h"

u8 *drvStr[10] = 
{
	(u8*)"�������    ",
	(u8*)"������ˢ���",
	(u8*)"ֱ����ˢ���",
	(u8*)"���巽������",
	(u8*)"�����л�����",
	(u8*)"            ",
	(u8*)"            "
};

///Show
int DriverUI::Show()
{
	return Show(selVal);
}

///Show
int DriverUI::Show(int operation)
{
	selVal = operation;
	bsp->ClearLcd();
	bsp->WriteLcd(2,0,(u8*)"*");
	
	bsp->WriteLcd(2,0,drvStr[selVal]);
	bsp->WriteLcd(2,1,drvStr[selVal+1]);
	bsp->WriteLcd(2,2,drvStr[selVal+2]);

	bsp->WriteLcd(0,3,(u8*)"ȷ��");
	bsp->WriteLcd(12,3,(u8*)"ȡ��");
	return 0;
}


