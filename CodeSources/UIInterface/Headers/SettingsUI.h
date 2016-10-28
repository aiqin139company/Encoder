#ifndef _SETTINGS_UI_H_
#define _SETTINGS_UI_H_
#include "UIInterface.h"

class SettingsUI : public UIInterface
{
private:

public:
		
	virtual int Show();
	virtual int Show(int operation);

};


#endif

