#ifndef _COMM_UI_H_
#define _COMM_UI_H_
#include "UIInterface.h"

class CommUI : public UIInterface
{
private:
	
	int TxMessage();
	int RxMessage();

public:

	virtual int Show(int operation);

};

#endif
