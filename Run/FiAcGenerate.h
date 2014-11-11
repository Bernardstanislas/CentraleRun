#pragma once

#include "config.h"

#include "FieldAction.h"

class FiAcGenerate :
	public FieldAction
{
private:
	int blockCount = 0;
	int complexity;
public:
	FiAcGenerate(int complexity = 0);
	void createSequence();
	void execute();
};
