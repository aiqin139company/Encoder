#ifndef _FIXED_UI_H_
#define _FIXED_UI_H_
#include "UIInterface.h"

class FixedUI : public UIInterface
{
private:
	
	int Home();
	int Menu();

public:

	virtual int Show(int operation);
	
};

#endif

