#pragma once
#include "SpriteAction.h"
class SpAcJump :
	public SpriteAction
{
protected:
	int duration;
	int elapsedTime;
public:
	SpAcJump();
	~SpAcJump();
	void execute();
};
