#ifndef _STEEPPER_H_
#define _STEEPPER_H_
#include "BaseDriver.h"

class Stepper : public BaseDriver
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

