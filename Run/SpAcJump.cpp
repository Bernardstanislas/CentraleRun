#include "SpAcJump.h"
#include "config.h"
#include <cmath>
#include "Sprite.h"

SpAcJump::SpAcJump(int height) : height(height)
{
	//duration = ceil(FRAMERATE/(2*height-1))*(2*height-1); Not sure if duration has to be an entire number of frame.
	duration = FRAMERATE;
	elapsedTime = 0;
}



FieldAction* SpAcJump::execute()
{
	auto XY = source->getPosition();
	
	int thisHeight = (4 * height / duration)*(-(elapsedTime*elapsedTime) / duration + elapsedTime);
	int nextHeight = (4 * height / duration)*(-((elapsedTime+1)*(elapsedTime+1)) / duration + elapsedTime+1);

	if (elapsedTime < duration){
		source->setPosition(XY.first, XY.second + nextHeight - thisHeight);
	}
	elapsedTime++;
	return nullptr;
}