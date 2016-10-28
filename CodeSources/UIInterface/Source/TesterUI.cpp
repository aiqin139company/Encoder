#include "TesterUI.h"

///Show
int TesterUI::Show(int operation)
{
	bsp->ClearLcd();
	bsp->WriteLcd(operation,2,2,(u8*)"*");
	bsp->WriteLcd(0,4,8,(u8*)"捕获测试");
	bsp->WriteLcd(1,4,8,(u8*)"计算脉冲");
	bsp->WriteLcd(2,4,8,(u8*)"相位偏差");
	bsp->WriteLcd(3,0,4,(u8*)"确定");
	bsp->WriteLcd(3,12,4,(u8*)"取消");
	return 0;
}


///Change Input Signal
int TesterUI::ChangeInputSignal()
{
	
	return 0;
}


///Capture Test
int TesterUI::CaptureTest()
{

	return 0;
}


///Count Pulse
int TesterUI::CountPulse()
{

	return 0;
}


///Phase Shift
int TesterUI::PhaseShift()
{

	return 0;
}


