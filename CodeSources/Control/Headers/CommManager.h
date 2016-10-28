#ifndef _COMM_MANAGER_H_
#define _COMM_MANAGER_H_
#include "BSPManager.h"

class CommManager
{
private:

	BSPManager* bsp;

public:

	int Initialize();
	int GetMsg();
	int ChangeMsg();
	int TxMessage();
	int RxMessage();

};

#endif

