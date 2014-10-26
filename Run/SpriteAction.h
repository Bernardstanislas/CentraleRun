#pragma once

#include "Action.h"
#include "Sprite.h"

class SpriteAction :
	public Action
{
protected:
	shared_ptr<Sprite> source;
	int duration;
	int elapsedTime;
public:
	virtual void execute() = 0;
};
