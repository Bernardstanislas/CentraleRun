#pragma once
#include "SpriteAction.h"

class SpAcJump :
	public SpriteAction
{
private:
	int height;
public:
	SpAcJump(int height = 4);
	FieldAction* execute();
};
