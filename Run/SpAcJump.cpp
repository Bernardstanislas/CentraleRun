#include "SpAcJump.h"
#include "config.h"
#include <cmath>
#include "Sprite.h"

SpAcJump::SpAcJump(int height) : height(height), SpriteAction(FRAMERATE/3)
{

}


FieldAction* SpAcJump::execute()
{
	auto XY = source->getPosition();

	int thisHeight = (4 * height / getDuration()) * (- (getTime() * getTime()) / getDuration() + getTime());
	int nextHeight = (4 * height / getDuration()) * (- ((getTime() + 1) * (getTime() + 1)) / getDuration() + getTime() + 1);

	incTime();
	if (getTime() <= getDuration())
		source->setPosition(XY.first, XY.second + nextHeight - thisHeight);
	
	return nullptr;
}