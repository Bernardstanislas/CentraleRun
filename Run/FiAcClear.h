#pragma once
#include "FieldAction.h"
class FiAcClear :
	public FieldAction
{
protected:
	int duration;
	int elapsedTime;
public:
	FiAcClear();
	~FiAcClear();
	void execute();
};
