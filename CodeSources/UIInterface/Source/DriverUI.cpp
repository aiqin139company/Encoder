#include "DriverUI.h"

///Show
int DriverUI::Show(int operation)
{
	bsp->ClearLcd();
	bsp->WriteLcd(0-operation,2,8,(u8*)"步进电机");
	bsp->WriteLcd(1-operation,2,12,(u8*)"交流无刷电机");
	bsp->WriteLcd(2-operation,2,12,(u8*)"直流有刷电机");
	bsp->WriteLcd(3-operation,2,12,(u8*)"脉冲方向驱动");
	bsp->WriteLcd(4-operation,2,12,(u8*)"开关切换驱动");
	
	bsp->WriteLcd(3,0,4,(u8*)"确定");
	bsp->WriteLcd(3,12,4,(u8*)"取消");
	return 0;
}


///DC Brushed
int DriverUI::DCBrushed()
{

	return 0;
}


///Step Dir Signal
int DriverUI::StepDirSignal()
{
	
	return 0;
}


///AC Brushed
int DriverUI::ACBrushed()
{

	return 0;
}


///Stepper
int DriverUI::Stepper()
{

	return 0;
}


///Switch
int DriverUI::Switch()
{

	return 0;
}

