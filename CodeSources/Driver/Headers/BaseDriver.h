#ifndef _BASE_DRIVER_H_
#define _BASE_DRIVER_H_
#include "BSPManager.h"

class BaseDriver
{
private:
	
public:
	
	BSPManager* bsp;
	BaseDriver() : bsp(BSPManager::Instance()) {}
	virtual int Start();
	virtual int Stop();
	virtual int Enable();
	virtual int Disable();
	virtual int IsFullSpeed();

};

#endif

