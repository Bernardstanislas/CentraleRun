#include "SpAcMove.h"
#include "Sprite.h"

SpAcMove::SpAcMove(int speed) : speed(speed)
{
	duration = -1;
}

FieldAction* SpAcMove::execute()
{
	auto XY = source->getPosition();
	source->setPosition(XY.first + speed, XY.second);
	return nullptr;
}