#pragma once

#include "Action.h"
#include "FieldAction.h"

class Sprite;

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
