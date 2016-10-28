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
	static RunMode localRunMode = homeSelectMode;
	
	switch( runMode )
	{
		case homeSelectMode 		: HomeSelect();			break;
		case menuSelectMode 		: MenuSelect(); 		break;
		case setDriverMode 			: SetDriver(); 			break;
		case setEncoderMode 		: SetEncoder(); 		break;
		case settingsMode				: Settings();				break;
		case testMode 					: StartStopTest();	break;
		default : break;
	}

	if ( localRunMode != runMode )
	{
		localRunMode = runMode;
		ui.ChangeUI(runMode);
		bUI = ui.GetUI();
		bUI->Show();
	}
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
			case selectTest : runMode = testMode; break;
			default : break;
		}
		return 0;
	}
	
	bUI->Show(localSelect);
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
		return 0;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		switch( localSelect )
		{
			case selectDriver : runMode = setDriverMode; break;
			case selectEncoder : runMode = setEncoderMode; break;
			case selectSettings : runMode = settingsMode; break;
			default : break;
		}
		return 0;
	}
	
	switch ( selectLoop )
	{
		case 0 : localSelect = selectDriver; break;
		case 1 : localSelect = selectEncoder; break;
		case 2 : localSelect = selectSettings; break;
		default : break;
	}
	
	bUI->Show(selectLoop);
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
		return 0;
	}
	else if ( KEY_CONFIRM == keyVal )
	{
		bDrv = driver.GetDriver();
		return 0;
	}
	
	bUI->Show(selectLoop);
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
		bEncoder = encoder.GetEncoder();
	}
	
	bUI->Show(selectLoop);
	encoder.ChangeEncoder(selectLoop);
	
	return 0;
}


///Set Test
int ControlManager::Settings()
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
		bDrv->Start();
		bEncoder->Start();
	}
	
	selectMode = localSelect;

	return 0;
}


///Monitor
int ControlManager::Monitor()
{
	if ( selectStartTest == selectMode )
	{
		bUI->Show(1);
	}
	else if ( selectEncoder == selectMode )
	{
	
	}
	
	return 0;
}

