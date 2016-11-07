#ifndef _SWITCH_H_
#define _SWITCH_H_
#include "BaseDriver.h"

class Switch : public BaseDriver
{
private:
		
public:

	virtual int Start();
	virtual int Stop();
	virtual int Enable();
	virtual int Disable();
	
};

#endif

