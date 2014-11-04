#pragma once

#include "Action.h"

// forward declaration to avoid cyclic inclusion
class Field;

class FieldAction :
	public Action
{
protected:
	Field *target;
	int duration;
	int elapsedTime;
public:
	virtual void execute() = 0;
};
