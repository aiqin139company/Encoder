#include "BaseDriver.h"

///BaseDriver
BaseDriver::BaseDriver()
	: bsp(BSPManager::Instance()),
		isFullSpeed(false)
{
}


///Start
int BaseDriver::Start()
{

	return 0;
}


///Stop
int BaseDriver::Stop()
{

	return 0;
}


///Enable
int BaseDriver::Enable()
{

	return 0;
}


///Disable
int BaseDriver::Disable()
{

	return 0;
}


///IsFullSpeed
bool BaseDriver::IsFullSpeed()
{
	return isFullSpeed;
}


