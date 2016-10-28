#ifndef _DC_BRUSHED_H_
#define _DC_BRUSHED_H_
#include "BaseDriver.h"

class DCBrushed : public BaseDriver
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

