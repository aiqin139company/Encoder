#ifndef _PULSE_GEN_H_
#define _PULSE_GEN_H_

#include "arm_math.h"
#define j2h(x) (PI*(x)/180.0f)

class PulseGen
{
private:
	
	float angle;
	float stepAngle;	
		
public:	

	uint16_t Freq;				//input : the freq output value which we want to output at last 
	uint16_t Times;				//input : times
	uint16_t Out;					//output

	PulseGen()
		: angle(0.0f),
		 stepAngle(0.0f),
		 Out(0)
	{
	}
	
	void Set()
	{
		Out = 0;
		angle = 0;
		stepAngle = 90.0f / Times;
	}
	
	void Marco()
	{
		if ( angle <= 90.0f )
		{
			Out = uint16_t(arm_sin_f32(j2h(angle)) * (float)Freq);
			angle += stepAngle;
		}	
		else
			Out = Freq;
	}

};

#endif /* _PULSE_GEN_H_ */

