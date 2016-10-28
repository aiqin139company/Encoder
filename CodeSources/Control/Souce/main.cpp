#include "ControlManager.h"

ControlManager ControlManager::control = ControlManager();

int main(void)
{
	ControlManager::control.Initialize();
	ControlManager::control.Execute();
}


