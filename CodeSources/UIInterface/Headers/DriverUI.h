#ifndef _DRIVER_UI_H_
#define _DRIVER_UI_H_
#include "UIInterface.h"

class DriverUI : public UIInterface
{
private:

public:
	
	int DCBrushed();
	int StepDirSignal();
	int ACBrushed();
	int Stepper();
	int Switch();

};

#endif

