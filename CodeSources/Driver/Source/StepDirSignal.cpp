#include "StepDirSignal.h"

///Start
int StepDirSignal::Start()
{
	bsp->WritePWM(168,100,50);
	return 0;
}


///Stop
int StepDirSignal::Stop()
{
	bsp->WritePWM(168,100,0);
	return 0;
}


///Enable
int StepDirSignal::Enable()
{

	return 0;
}


///Disable
int StepDirSignal::Disable()
{

	return 0;
}


///IsFullSpeed
int StepDirSignal::IsFullSpeed()
{
	
	return 0;
}
