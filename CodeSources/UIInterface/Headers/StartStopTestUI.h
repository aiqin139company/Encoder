#ifndef _START_STOP_TEST_UI_H_
#define _START_STOP_TEST_UI_H_
#include "UIInterface.h"

class StartStopTestUI : public UIInterface
{
private:
	
	int StartTest();
	int StopTest();

public:
	
	virtual int Show(int operation);

};

#endif
