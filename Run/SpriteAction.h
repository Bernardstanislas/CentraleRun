#pragma once

#include "Action.h"
#include "Sprite.h"

class SpriteAction :
	public Action
{
protected:
	virtual Sprite source;
	virtual int duration;
	virtual int elapsedTime;
public:
	virtual void execute() = 0;
};
