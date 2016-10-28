#ifndef _TESTER_UI_
#define _TESTER_UI_
#include "UIInterface.h"

class TesterUI : UIInterface
{
private:
	
	int ChangeInputSignal();
	int CaptureTest();
	int CountPulse();
	int PhaseShift();

public:

	virtual int Show(int operation);

};

#endif

