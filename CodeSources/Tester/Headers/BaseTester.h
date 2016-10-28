#ifndef _BASE_TESTER_H_
#define _BASE_TESTER_H_
#include "BSPManager.h"

class BaseTester
{
private:

public:
	
	BSPManager* bsp;
	BaseTester() { bsp = BSPManager::Instance(); }
	virtual int Start();
	virtual int Stop();
	virtual int	GetInfo();

};

#endif

