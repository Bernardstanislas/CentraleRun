#pragma once

#include "SpriteAction.h"
#include "Direction.h"

class SpAcMove :
	public SpriteAction
{
protected:
	unsigned int speed;
	Direction direction;
	int loopTime;
public:
	SpAcMove(unsigned int speed, Direction direction, int loopTime = 0);
	FieldAction* execute();
};
