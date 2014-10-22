#pragma once

#include "Action.h"
#include "Field.h"

class FieldAction :
	public Action
{
protected:
	Field source;
public:
	FieldAction(int duration, Field &source);
	~FieldAction();
};
