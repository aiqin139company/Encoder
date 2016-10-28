#ifndef _ENCODER_MANAGER_H_
#define _ENCODER_MANAGER_H_
#include "BaseTester.h"
#include "CaptureTest.h"
#include "CountPulse.h"
#include "PhaseShift.h"

enum SelEncoder
{
	captureTest = 0,
	countPulse,
	phaseShift,
	ENCODERSIZES
};

class EncoderManager
{
private:

	BaseEncoder* bEncoder;
	CaptureTest CaptureTest;
	CountPulse	CountPulse;
	PhaseShift  PhaseShift;

public:

	int Initialize();
	BaseEncoder* GetEncoder();
	int ChangeEncoder(int selVal);

};

#endif

