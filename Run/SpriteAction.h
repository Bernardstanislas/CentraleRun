#pragma once

#include "Action.h"
#include "Sprite.h"

class SpriteAction :
	public Action
{
protected:
	Sprite *source;
	int duration;
	int elapsedTime;
public:
	virtual void execute() = 0;
};
