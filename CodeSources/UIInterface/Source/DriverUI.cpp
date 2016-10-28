#include "DriverUI.h"

///Show
int DriverUI::Show(int operation)
{
	bsp->ClearLcd();
	bsp->WriteLcd(0-operation,2,8,(u8*)"�������");
	bsp->WriteLcd(1-operation,2,12,(u8*)"������ˢ���");
	bsp->WriteLcd(2-operation,2,12,(u8*)"ֱ����ˢ���");
	bsp->WriteLcd(3-operation,2,12,(u8*)"���巽������");
	bsp->WriteLcd(4-operation,2,12,(u8*)"�����л�����");
	
	bsp->WriteLcd(3,0,4,(u8*)"ȷ��");
	bsp->WriteLcd(3,12,4,(u8*)"ȡ��");
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

