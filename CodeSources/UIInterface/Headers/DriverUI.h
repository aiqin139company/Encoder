#ifndef _DRIVER_UI_H_
#define _DRIVER_UI_H_
#include "UIInterface.h"

class DriverUI : public UIInterface
{
private:

public:
	
	virtual int Show();
	virtual int Show(int operation);

};

#endif

