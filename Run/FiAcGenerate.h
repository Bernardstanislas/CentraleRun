#pragma once

#include "config.h"

#include "FieldAction.h"

class FiAcGenerate :
	public FieldAction
{
private:
	int blockCount = 0;
	int complexity = 0;
public:
	FiAcGenerate();
	void createSequence();
	void execute();
};
