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
	virtual FieldAction* execute() = 0;
	void setSource(Sprite* source);
};

typedef std::unique_ptr<SpriteAction> pSpriteAction;