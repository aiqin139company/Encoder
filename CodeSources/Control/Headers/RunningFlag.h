#ifndef _RUNNING_FLAG_H_
#define _RUNNING_FLAG_H_

///Running Mode
enum RunMode
{
	homeSelectMode = 0,
	menuSelectMode,
	setDriverMode,
	setEncoderMode,
	settingsMode,
	testMode,
};


///Select Mode
enum SelectMode
{
	noSelect = 0,
	selectMenu,
	selectTest,
	selectDriver,
	selectEncoder,
	selectSettings,
	selectStartTest,
	selectStopTest,
};

#endif

