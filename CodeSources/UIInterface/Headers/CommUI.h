#ifndef _COMM_UI_H_
#define _COMM_UI_H_
#include "UIInterface.h"

class CommUI : public UIInterface
{
private:

public:

	int TxMessage();
	int RxMessage();

};

#endif
