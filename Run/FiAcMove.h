#pragma once
#include "FieldAction.h"
class FiAcMove :
	public FieldAction
{
protected:
	int duration;
	int elapsedTime;
public:
	FiAcMove();
	~FiAcMove();
	void execute();
};
