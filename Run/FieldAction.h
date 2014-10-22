#pragma once

#include "Action.h"
#include "Field.h"

class FieldAction :
	public Action
{
protected:
	virtual Field target;
	virtual int duration;
	virtual int elapsedTime;
public:
	virtual void execute() = 0;
};
