#ifndef _AC_BRUSHLESS_H_
#define _AC_BRUSHLESS_H_
#include "BaseDriver.h"

class ACBrushed	: public BaseDriver
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

