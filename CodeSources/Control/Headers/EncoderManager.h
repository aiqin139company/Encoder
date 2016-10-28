#ifndef _ENCODER_MANAGER_H_
#define _ENCODER_MANAGER_H_
#include "BaseTester.h"
#include "CaptureTest.h"
#include "CountPulse.h"
#include "PhaseShift.h"

enum SelTester
{
	captureTest = 0,
	countPulse,
	phaseShift,
	ENCODERSIZES
};

class EncoderManager
{
private:

	BaseTester* bTest;
	CaptureTest CaptureTest;
	CountPulse	CountPulse;
	PhaseShift  PhaseShift;

public:

	int Initialize();
	BaseTester* GetTester();
	int ChangeTester(int selVal);

};

#endif

