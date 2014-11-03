#include "SpAcMove.h"
#include "Sprite.h"

SpAcMove::SpAcMove(int speed) : speed(speed)
{
	duration = -1;
}

void SpAcMove::execute()
{
	auto XY = source->getPosition();
	source->setPosition(XY.first + speed, XY.second);
}