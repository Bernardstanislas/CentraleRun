#pragma once

#include "Action.h"
#include "Field.h"

class SpAcFieldAction :
	public Action
{
protected:
	Field source;
public:
	SpAcFieldAction(int duration, Field &source);
	~SpAcFieldAction();
};
