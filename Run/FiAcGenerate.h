#pragma once
#include "FieldAction.h"
class FiAcGenerate :
	public FieldAction
{
protected:
	int duration;
	int elapsedTime;
public:
	FiAcGenerate();
	~FiAcGenerate();
	void execute();
};
