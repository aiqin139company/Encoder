#ifndef _UI_INTERFACE_H_
#define _UI_INTERFACE_H_
#include "BSPManager.h"
#include "RunningFlag.h"

class UIInterface
{
private:

public:
	
	int selVal;
	BSPManager* bsp;

	UIInterface() { bsp = BSPManager::Instance(); selVal = 0; }
	virtual int Show();
	virtual int Show(int operation);

};

#endif
