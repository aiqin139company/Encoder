#include "StepDirSignal.h"

//168Mhz/10=16.8Mhz  16.8Mhz/168=100Khz	
const u16 pscMax = 10;
const u16 arrMax = 168;
const u16 times = 500;

///Start
int StepDirSignal::Start()
{
	pg.Freq = arrMax;
	pg.Times = times;
	pg.Set();
	return 0;
}


///Stop
int StepDirSignal::Stop()
{
	Disable();
	return 0;
}


///Enable
int StepDirSignal::Enable()
{
	if ( pg.Out != pg.Freq )
	{
		pg.Marco();
		u16 arr = pg.Out;
		bsp->WritePWM(pscMax,arr,arr>>1);
	}
	else
		isFullSpeed = true;
	
	return isFullSpeed;
}


///Disable
int StepDirSignal::Disable()
{
	isFullSpeed = false;
	bsp->WritePWM(168,100,0);
	return 0;
}

