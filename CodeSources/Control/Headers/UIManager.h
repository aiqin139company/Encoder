#ifndef _UI_MANAGER_H_
#define _UI_MANAGER_H_
#include "UIInterface.h"
#include "RunningFlag.h"

class UIManager
{
private:
 
	UIInterface* uiInterface;
	UIInterface  DriverUI;
	UIInterface  TesterUI;
	UIInterface  StartStopTestUI;
	UIInterface  CommUI;
	UIInterface  FixedUI;

public:
	
	int Initialize();
	UIInterface* GetUI();
	int ChangeUI(RunMode runMode,SelectMode selectMode);
	int ShowUI();

};

#endif
