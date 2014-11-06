#include "SpAcJump.h"
#include "config.h"
#include <cmath>
#include "Sprite.h"
#include <iostream>

SpAcJump::SpAcJump(int height) : height(height), SpriteAction(FRAMERATE)
{

}


FieldAction* SpAcJump::execute()
{
	auto XY = source->getPosition();

	int thisHeight = (4 * height / Action::duration)*(-(Action::elapsedTime*Action::elapsedTime) / Action::duration + Action::elapsedTime);
	int nextHeight = (4 * height / Action::duration)*(-((Action::elapsedTime + 1)*(Action::elapsedTime + 1)) / Action::duration + Action::elapsedTime + 1);

	Action::elapsedTime++;
	if (Action::elapsedTime <= Action::duration){
		SpriteAction::source->setPosition(XY.first, XY.second + nextHeight - thisHeight);
	}
	
	return nullptr;
}