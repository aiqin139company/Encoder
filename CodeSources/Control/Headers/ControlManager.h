#ifndef _CONTROL_MANANGER_H_
#define _CONTROL_MANANGER_H_
#include "CommManager.h"
#include "DriverManager.h"
#include "EncoderManager.h"
#include "UIManager.h"
#include "BSPManager.h"
#include "RunningFlag.h"

class ControlManager
{
private:
	
	//members
	CommManager 		comm;
	DriverManager 	driver;
	EncoderManager 	encoder;
	UIManager				ui;
	BSPManager*			bsp;

	BaseDriver*			bDrv;
	BaseEncoder*		bEncoder;
	BaseComm*				bComm;
	UIInterface*		bUI;

	RunMode					runMode; 
	SelectMode			selectMode;
	int 						keyVal;
	int 						commSizes;
	int 						driverSizes;
	int 						encoderSizes;

	//methods
	void Controller();
	int HomeSelect();
	int MenuSelect();
	int SetDriver();
	int SetEncoder();
	int Settings();
	int StartStopTest();
	int Monitor();

public:
		
	//members
	static ControlManager control;

	//methods
	ControlManager();
	void Initialize();
	void Execute();
	
};


#endif

