#pragma once

#include "Action.h"

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
	void setTarget(Field* target);
};
