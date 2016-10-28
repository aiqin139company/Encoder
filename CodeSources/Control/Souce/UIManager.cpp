#include "UIManager.h"

///Initialize
int UIManager::Initialize()
{
	uiInterface = &HomeUI;
	uiInterface->Show(1);
	return 0;
}


///Get UI
UIInterface* UIManager::GetUI()
{
	return uiInterface;
}


///Change UI
int UIManager::ChangeUI(RunMode runMode)
{
	switch( runMode )
	{
		case homeSelectMode : uiInterface = &HomeUI; break;
		case menuSelectMode : uiInterface = &MenuUI; break;
		case setDriverMode  : uiInterface = &DriverUI; break;
		case setEncoderMode : uiInterface = &EncoderUI; break;
		case settingsMode   : uiInterface = &SettingsUI; break;
		case testMode			  : uiInterface = &TestUI; break;
		default : break;
	}
	
	return 0;
}



