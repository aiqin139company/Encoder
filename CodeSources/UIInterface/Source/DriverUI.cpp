#include "DriverUI.h"

u8 *drvStr[10] = 
{
	(u8*)"步进电机    ",
	(u8*)"交流无刷电机",
	(u8*)"直流有刷电机",
	(u8*)"脉冲方向驱动",
	(u8*)"开关切换驱动",
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
	bsp->WriteLcd(0,2,(u8*)"*");
	
	bsp->WriteLcd(0,2,drvStr[selVal]);
	bsp->WriteLcd(1,2,drvStr[selVal+1]);
	bsp->WriteLcd(2,2,drvStr[selVal+2]);

	bsp->WriteLcd(3,0,(u8*)"确定");
	bsp->WriteLcd(3,12,(u8*)"取消");
	return 0;
}


