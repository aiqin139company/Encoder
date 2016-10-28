#include "FixedUI.h"

///Show
int FixedUI::Show(int operation)
{
	switch(operation)
	{
		case 0 : Home(); break; 
		case 1 : Menu(); break;
	}
	return 0;
}


///Home
int FixedUI::Home()
{
	bsp->ClearLcd();
	bsp->WriteLcd(1,6,4,(u8*)"����");
	bsp->WriteLcd(2,6,4,(u8*)"����");
	bsp->WriteLcd(3,0,4,(u8*)"ȷ��");
	bsp->WriteLcd(3,12,4,(u8*)"ȡ��");
	
	bsp->WriteLcd(1,4,1,(u8*)"*");
	
	return 0;
}


///Menu
int FixedUI::Menu()
{
	bsp->ClearLcd();
	bsp->WriteLcd(0,4,8,(u8*)"��������");
	bsp->WriteLcd(1,4,8,(u8*)"���õ��");
	bsp->WriteLcd(2,4,8,(u8*)"���ò���");
	bsp->WriteLcd(3,0,4,(u8*)"ȷ��");
	bsp->WriteLcd(3,12,4,(u8*)"ȡ��");
	
	bsp->WriteLcd(0,4,1,(u8*)"*");
	
	return 0;
}

