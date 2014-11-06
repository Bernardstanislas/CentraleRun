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
	FieldAction(int duration = -1);
	virtual void execute() = 0;
	void setTarget(Field* target);
};
