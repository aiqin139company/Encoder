#ifndef _ENCODER_UI_H_
#define _ENCODER_UI_H_
#include "UIInterface.h"

class EncoderUI : public UIInterface
{
private:

public:

	virtual int Show();
	virtual int Show(int operation);

};

#endif

