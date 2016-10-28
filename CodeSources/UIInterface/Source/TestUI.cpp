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
	bsp->WriteLcd(0,4,(u8*)"���ڲ���");
	bsp->WriteLcd(1,4,selVal ? (u8*)"����ͨ��" : (u8*)"����ʧ��");
	bsp->WriteLcd(3,0,(u8*)"ȷ��");
	bsp->WriteLcd(3,12,(u8*)"ȡ��");
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

