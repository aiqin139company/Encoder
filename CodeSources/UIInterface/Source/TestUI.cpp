#include "TestUI.h"

///Show
int TestUI::Show()
{
	return Show(selVal);
}

///Show
int TestUI::Show(int operation)
{
	selVal = operation;
	bsp->ClearLcd();
	bsp->WriteLcd(4,0,(u8*)"���ڲ���");
	bsp->WriteLcd(4,1,selVal ? (u8*)"����ͨ��" : (u8*)"����ʧ��");
	bsp->WriteLcd(0,3,(u8*)"ȷ��");
	bsp->WriteLcd(12,3,(u8*)"ȡ��");
	return 0;
}


///Start Test
int TestUI::StartTest()
{

	return 0;
}


///Stop Test
int TestUI::StopTest()
{
	
	return 0;
}

