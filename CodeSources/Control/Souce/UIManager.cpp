#include "UIManager.h"

///Initialize
int UIManager::Initialize()
{
	uiInterface = &FixedUI;
	uiInterface->Show(0);
	return 0;
}


///Get UI
UIInterface* UIManager::GetUI()
{
	return uiInterface;
}


///Change UI
int UIManager::ChangeUI(RunMode runMode,SelectMode selectMode)
{
	switch( runMode )
	{
		case homeSelectMode :
		case menuSelectMode : uiInterface = &FixedUI; break;
		case setDriverMode  : uiInterface = &DriverUI; break;
		case setEncoderMode : uiInterface = &TesterUI; break;
		case setTestMode    : 
		case startStopTestMode : uiInterface = &StartStopTestUI; break;
		default : break;
	}
	
	return 0;
}



