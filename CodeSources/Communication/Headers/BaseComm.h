#ifndef _BASE_COMM_H_
#define _BASE_COMM_H_
#include "BSPManager.h"

class BaseComm
{
private:

public:
	
	BSPManager* bsp;
	BaseComm() { bsp = BSPManager::Instance(); }
	virtual int TxMessage(int num, u8* TxBuffer);
	virtual int RxMessage(int num, u8* RxBuffer);
	
};

#endif

