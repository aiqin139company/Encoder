#ifndef _SCI_COMM_H_
#define _SCI_COMM_H_
#include "BaseComm.h"

class SciComm : public BaseComm
{
private:

public:
	
	virtual int TxMessage(int num, u8* TxBuffer);
	virtual int RxMessage(int num, u8* RxBuffer);

};

#endif

