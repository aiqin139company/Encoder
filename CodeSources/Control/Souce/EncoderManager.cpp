#include "EncoderManager.h"

///Initialize
int EncoderManager::Initialize()
{
	return ENCODERSIZES-1;
}


///Get Tester
BaseTester* EncoderManager::GetTester()
{
	return bTest;
}


///Change Tester
int EncoderManager::ChangeTester(int selVal)
{
	switch ( (SelTester)selVal )
	{
		case captureTest : bTest = &CaptureTest; break;
		case countPulse : bTest = &CountPulse; break;
		case phaseShift : bTest = &PhaseShift; break;
		default : break;
	}
	return 0;
}

