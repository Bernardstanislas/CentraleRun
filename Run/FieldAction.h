#pragma once

#include "Action.h"
#include "Field.h"

class FieldAction :
	public Action
{
protected:
	Field target;
	int duration;
	int elapsedTime;
public:
	virtual void execute() = 0;
};
