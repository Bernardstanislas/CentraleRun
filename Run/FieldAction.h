#pragma once

#include "Action.h"
#include <memory>

class Field;

class FieldAction :
	public Action
{
protected:
	Field *target;
public:
	FieldAction(int duration = -1);
	virtual void execute() = 0;
	void setTarget(Field* target);
};

typedef std::unique_ptr<FieldAction> pFieldAction;