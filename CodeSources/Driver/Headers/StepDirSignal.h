#ifndef _STEP_DIR_SIGNAL_H_
#define _STEP_DIR_SIGNAL_H_
#include "BaseDriver.h"
#include "PulseGen.h"

class StepDirSignal : public BaseDriver
{
private:	

	PulseGen pg;

public:
	
	virtual int Start();
	virtual int Stop();
	virtual int Enable();
	virtual int Disable();

};

#endif

