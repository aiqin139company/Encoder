#ifndef _CAPTURE_TEST_H_
#define _CAPTURE_TEST_H_
#include "BaseTester.h"

class CaptureTest : public BaseEncoder
{
private:
		
public:
	
	virtual int Start();
	virtual int Stop();
	virtual int GetInfo();
	virtual int ChangeInputSignal(int signal);

};

#endif

