#ifndef _COMM_MANAGER_H_
#define _COMM_MANAGER_H_
#include "BaseComm.h"
#include "SciComm.h"

enum SelComm
{	
	sci = 0,
	COMMSIZES
};

class CommManager
{
private:
	
	BaseComm* bComm;
	SciComm   SciComm;

public:

	int Initialize();
	BaseComm* GetMsg();
	int ChangeMsg(int selVal);

};

#endif

