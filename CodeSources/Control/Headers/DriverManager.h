#ifndef _DRIVER_MANAGER_H_
#define _DRIVER_MANAGER_H_
#include "BaseDriver.h"
#include "DCBrushed.h"
#include "StepDirSignal.h"
#include "ACBrushless.h"
#include "Stepper.h"
#include "Switch.h"

enum SelDriver
{	
	stepper = 0,
	acBrushless, 
	dcBrushed,
	stepDirSignal,
	switchSignal,
	DRIVERSIZES
};

class DriverManager
{
private:
		
	BaseDriver*		bDrv;
	ACBrushed 		ACBrushless;
	DCBrushed 		DCBrushed;
	StepDirSignal StepDirSignal;
	Stepper 			Stepper;
	Switch 				Switch;

public:
		
	int Initialize();
	BaseDriver* GetDriver();
	int ChangeDriver(int ctrlVal);

};

#endif
