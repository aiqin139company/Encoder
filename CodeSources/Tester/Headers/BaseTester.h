#ifndef _BASE_ENCODER_H_
#define _BASE_ENCODER_H_
#include "BSPManager.h"

class BaseEncoder
{
private:

public:
	
	BSPManager* bsp;
	BaseEncoder() { bsp = BSPManager::Instance(); }
	virtual int Start();
	virtual int Stop();
	virtual int	GetInfo();
	virtual int ChangeInputSignal(int signal);

};

#endif

