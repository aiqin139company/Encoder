#include "CommUI.h"

///Show
int CommUI::Show()
{
	return Show(selVal);
}


///Show
int CommUI::Show(int operation)
{
	selVal = operation;
	operation ? TxMessage() : RxMessage();
	return 0;
}

///TxMessage
int CommUI::TxMessage()
{

	return 0;
}

///RxMessage
int CommUI::RxMessage()
{

	return 0;
}
	
