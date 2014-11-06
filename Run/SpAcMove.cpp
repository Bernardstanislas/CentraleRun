#include "SpAcMove.h"
#include "Sprite.h"
#include <iostream>

SpAcMove::SpAcMove(int speed) : speed(speed), SpriteAction()
{

}

FieldAction* SpAcMove::execute()
{
	auto XY = source->getPosition();
	source->setPosition(XY.first + speed, XY.second);
	return nullptr;
}