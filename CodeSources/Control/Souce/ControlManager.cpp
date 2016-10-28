#include "ControlManager.h"

//ControlManager
ControlManager::ControlManager()
	: runMode(homeSelectMode),
		selectMode(noSelect),
		keyVal(0),
		commSizes(0),
		driverSizes(0),
		encoderSizes(0)
{}

	
///Initialize
void ControlManager::Initialize()
{
	bsp = BSPManager::Instance();
	bsp->BSP_Init();
	commSizes = comm.Initialize();
	driverSizes = driver.Initialize();
	encoderSizes = encoder.Initialize();
	ui.Initialize();
}


///Execute
void ControlManager::Execute()
{
	while(1)
	{
		keyVal = bsp->ReadKey(KEY_SINGLE);
		if (keyVal)	Controller();
		Monitor();
	}
}


///Controller
void ControlManager::Controller()
{
	switch( runMode )
	{
		case homeSelectMode 		: HomeSelect();			break;
		case menuSelectMode 		: MenuSelect(); 		break;
		case setDriverMode 			: SetDriver(); 			break;
		case setEncoderMode 		: SetEncoder(); 		break;
		case setTestMode				: SetTest();				break;
		case startStopTestMode 	: StartStopTest();	break;
		default : break;
	}
	bUI->Show(keyVal);
	ui.ChangeUI(runMode,selectMode);
	bUI = ui.GetUI();
}


///Home Select
int ControlManager::HomeSelect()
{
	static SelectMode localSelect = selectMenu;
	
	if ( KEY_UP == keyVal )
	{
		localSelect = selectMenu;
	}
	else if ( KEY_DOWN == keyVal )
	{
		localSelect = selectTest;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		switch( localSelect )
		{
			case selectMenu : runMode = menuSelectMode; break;
			case selectTest : runMode = startStopTestMode; break;
			default : break;
		}
	}
	
	selectMode = localSelect;
	
	return 0;
}


///Select Menu
int ControlManager::MenuSelect()
{
	static SelectMode localSelect = selectDriver;
	static short selectLoop = 0;
	
	if ( KEY_UP == keyVal )
	{
		if ( --selectLoop < 0 ) selectLoop = 2;
	}
	else if ( KEY_DOWN == keyVal )
	{
		if ( ++selectLoop > 2 ) selectLoop = 0;
	}
	else if ( KEY_CANCEL == keyVal )
	{
		runMode = homeSelectMode;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		switch( localSelect )
		{
			case selectDriver : runMode = setDriverMode; break;
			case selectEncoder : runMode = setEncoderMode; break;
			case selectSetTest : runMode = setTestMode; break;
			default : break;
		}
	}
	
	switch ( selectLoop )
	{
		case 0 : localSelect = selectDriver; break;
		case 1 : localSelect = selectEncoder; break;
		case 2 : localSelect = selectSetTest; break;
		default : break;
	}
	
	selectMode = localSelect;

	return 0;
}


///Set Driver
int ControlManager::SetDriver()
{
	static short selectLoop = 0;
	
	if ( KEY_UP == keyVal )
	{
		if ( --selectLoop < 0 ) selectLoop = driverSizes;
	}
	else if ( KEY_DOWN == keyVal )
	{
		if ( ++selectLoop > driverSizes ) selectLoop = 0;
	}
	else if ( KEY_CANCEL == keyVal )
	{
		runMode = menuSelectMode;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		bDrv = driver.GetDriver();
	}
	
	driver.ChangeDriver(selectLoop);
	
	return 0;
}


///Set Encoder
int ControlManager::SetEncoder()
{
	static short selectLoop = 0;
	
	if ( KEY_UP == keyVal )
	{
		if ( --selectLoop < 0 ) selectLoop = encoderSizes;
	}
	else if ( KEY_DOWN == keyVal )
	{
		if ( ++selectLoop > encoderSizes ) selectLoop = 0;
	}
	else if ( KEY_CANCEL == keyVal )
	{
		runMode = menuSelectMode;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		bTester = encoder.GetTester();
	}
	
	encoder.ChangeTester(selectLoop);
	
	return 0;
}


///Set Test
int ControlManager::SetTest()
{
	if ( KEY_UP == keyVal )
	{
		
	}
	else if ( KEY_DOWN == keyVal )
	{
		
	}
	else if ( KEY_CANCEL == keyVal )
	{
		runMode = menuSelectMode;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		
	}
	
	return 0;
}


///Start Stop Test
int ControlManager::StartStopTest()
{
	static SelectMode localSelect = selectStopTest;
	
	if ( KEY_CANCEL == keyVal )
	{
		if ( selectStartTest == localSelect )
			localSelect = selectStopTest; 
		else 
			runMode = homeSelectMode;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		localSelect = selectStartTest;
		bTester->Start();
		bDrv->Start();
	}
	
	selectMode = localSelect;

	return 0;
}


///Monitor
int ControlManager::Monitor()
{
	if ( selectStartTest == selectMode )
	{
		
	}
	
	return 0;
}

