#ifndef _STEP_DIR_SIGNAL_H_
#define _STEP_DIR_SIGNAL_H_
#include "BaseDriver.h"

class StepDirSignal : public BaseDriver
{
private:
		
public:
	
	virtual int Start();
	virtual int Stop();
	virtual int Enable();
	virtual int Disable();
	virtual int IsFullSpeed();

};

#endif

