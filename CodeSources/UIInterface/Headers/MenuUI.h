#ifndef _MENU_UI_H_
#define _MENU_UI_H_
#include "UIInterface.h"

class MenuUI : public UIInterface
{
private:

public:

	virtual int Show();
	virtual int Show(int operation);
	
};

#endif

