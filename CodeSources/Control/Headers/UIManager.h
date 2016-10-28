#ifndef _UI_MANAGER_H_
#define _UI_MANAGER_H_
#include "UIInterface.h"
#include "CommUI.h"
#include "DriverUI.h"
#include "HomeUI.h"
#include "MenuUI.h"
#include "EncoderUI.h"
#include "SettingsUI.h"
#include "TestUI.h"
#include "RunningFlag.h"


class UIManager
{
private:
 
	UIInterface* uiInterface;
	CommUI			 CommUI;
	DriverUI	   DriverUI;
	HomeUI			 HomeUI;
	MenuUI		   MenuUI;
	EncoderUI	   EncoderUI;
	SettingsUI   SettingsUI;
	TestUI		   TestUI;

public:
	
	int Initialize();
	UIInterface* GetUI();
	int ChangeUI(RunMode runMode);

};

#endif
