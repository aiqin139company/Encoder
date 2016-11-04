#include "CommManager.h"

///Initialize
int CommManager::Initialize()
{
	bComm = &SciComm;
	return COMMSIZES-1;
}


///Get MSG
BaseComm* CommManager::GetMsg()
{
	return bComm;
}


///Change MSG 
int CommManager::ChangeMsg(int selVal)
{
	switch ( (SelComm)selVal )
	{
		case sci : bComm = &SciComm; break;
		default  : break;
	}
	return 0;
}


