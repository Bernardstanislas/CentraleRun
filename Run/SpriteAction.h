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
    // should be unique_ptr<FieldAction>? "unique_ptr does not name a type" :/
	virtual FieldAction* execute() = 0;
	void setSource(Sprite* source);
};
