#ifndef _START_STOP_TEST_UI_H_
#define _START_STOP_TEST_UI_H_
#include "UIInterface.h"

class TestUI : public UIInterface
{
private:
	
	int StartTest();
	int StopTest();

public:
	
	virtual int Show();
	virtual int Show(int operation);

};

#endif
