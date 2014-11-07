#pragma once

#include "Action.h"
#include "FieldAction.h"

class Sprite;

class SpriteAction :
	public Action
{
protected:
	Sprite *source;
public:
	SpriteAction(int duration = -1);
    // should be unique_ptr<FieldAction>? "unique_ptr does not name a type" :/
	virtual FieldAction* execute() = 0;
	void setSource(Sprite* source);
};
