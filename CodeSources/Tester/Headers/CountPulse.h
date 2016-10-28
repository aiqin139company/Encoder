#ifndef _COUNT_PULSE_H_
#define _COUNT_PULSE_H_
#include "BaseTester.h"

class CountPulse : public BaseEncoder
{
private:

public:
	
	virtual int Start();
	virtual int Stop();
	virtual int GetInfo();

};

#endif

