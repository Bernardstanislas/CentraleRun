#pragma once

#include <memory>
#include <vector>
#include <algorithm>

#include "Action.h"
#include "FieldAction.h"

// forward declaration to avoid cyclic inclusion
class Sprite;

class SpriteAction :
	public Action
{
protected:
	Sprite *source;
	int duration;
	int elapsedTime;
public:
    // shouldn't the return type be unique_ptr<FieldAction>?
    // This gives me a "'unique_ptr' does not have a type" error :/
    FieldAction* execute(Sprite* context);
	virtual void execute() = 0;
};
