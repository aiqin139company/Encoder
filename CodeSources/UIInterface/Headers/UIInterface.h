#ifndef _UI_INTERFACE_H_
#define _UI_INTERFACE_H_
#include "BSPManager.h"
#include "RunningFlag.h"

class UIInterface
{
private:

public:
	
	BSPManager* bsp;
	UIInterface() { bsp = BSPManager::Instance(); }
	virtual int Show(int operation);

};

#endif
