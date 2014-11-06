#pragma once

#include "config.h"

#include "FieldAction.h"

#define SEQUENCE_SIZE (WINDOW_WIDTH/BLOCKSIZE)

class FiAcGenerate :
	public FieldAction
{
private:
	int blockCount = 0;
	int speed;
public:
	FiAcGenerate(int speed);
	void execute();
};
