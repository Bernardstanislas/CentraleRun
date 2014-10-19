#pragma once

#include "Action.h"
#include "Sprite.h"

class SpriteAction :
	public Action
{
protected:
	Sprite source;
public:
	SpriteAction(int duration, Sprite &source);
	~SpriteAction();
};

