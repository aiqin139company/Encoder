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
	bsp->WriteLcd(4,0,(u8*)"正在测试");
	bsp->WriteLcd(4,1,selVal ? (u8*)"测试通过" : (u8*)"测试失败");
	bsp->WriteLcd(0,3,(u8*)"确定");
	bsp->WriteLcd(12,3,(u8*)"取消");
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

