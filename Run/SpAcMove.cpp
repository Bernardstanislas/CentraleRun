#include "SpAcMove.h"
#include "Sprite.h"
#include <iostream>

SpAcMove::SpAcMove(unsigned int speed, Direction direction, int loopTime) : speed(speed), direction(direction), loopTime(loopTime), SpriteAction()
{

}

FieldAction* SpAcMove::execute()
{
	if (loopTime != 0 && getTime() % loopTime == 0)
	{
		switch (direction)
		{
		case Direction::DOWN:
			direction = Direction::UP;
			break;
		case Direction::UP:
			direction = Direction::DOWN;
			break;
		case Direction::LEFT:
			direction = Direction::RIGHT;
			break;
		case Direction::RIGHT:
			direction = Direction::LEFT;
			break;
		}
	}

	auto XY = source->getPosition();
	auto newX = XY.first;
	auto newY = XY.second;

	switch (direction)
	{
	case Direction::DOWN:
		newY -= speed;
		break;
	case Direction::UP:
		newY += speed;
		break;
	case Direction::LEFT:
		newX -= speed;
		break;
	case Direction::RIGHT:
		newX += speed;
		break;
	}

	source->setNPosition(newX, newY);
	
	incTime();

	return nullptr;
}