#include "SpAcMove.h"
#include "Sprite.h"

SpAcMove::SpAcMove(int speed, int vspeed, int loopTime) : speed(speed), vspeed(vspeed), loopTime(loopTime), SpriteAction()
{

}

FieldAction* SpAcMove::execute()
{
	incTime();

	if (loopTime != 0 && getTime() % loopTime == 0)
	{
		speed = -speed;
		vspeed = -vspeed;
	}

	auto XY = source->getPosition();
	source->setPosition(XY.first + speed, XY.second + vspeed);

	return nullptr;
}