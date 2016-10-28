#include "EncoderManager.h"

///Initialize
int EncoderManager::Initialize()
{
	return ENCODERSIZES-1;
}


///Get Tester
BaseEncoder* EncoderManager::GetEncoder()
{
	return bEncoder;
}


///Change Tester
int EncoderManager::ChangeEncoder(int selVal)
{
	switch ( (SelEncoder)selVal )
	{
		case captureTest : bEncoder = &CaptureTest; break;
		case countPulse : bEncoder = &CountPulse; break;
		case phaseShift : bEncoder = &PhaseShift; break;
		default : break;
	}
	return 0;
}

