#include "DriverManager.h"


///Initialize
int DriverManager::Initialize()
{
	bDrv = &Stepper;
	return DRIVERSIZES-1;
}


///Get Driver
BaseDriver* DriverManager::GetDriver()
{
	return bDrv;
}


///Change Driver
int DriverManager::ChangeDriver(int selVal)
{
	switch ( (SelDriver)selVal )
	{
		case stepper 			: bDrv = &Stepper; 			break;
		case acBrushless 	: bDrv = &ACBrushless; 	break;
		case dcBrushed  	: bDrv = &DCBrushed; 		break;
		case stepDirSignal: bDrv = &StepDirSignal; break;	
		case switchSignal : bDrv = &Switch; 			break;
		default : break;
	}
	return 0;	
}

