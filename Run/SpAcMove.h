#pragma once
#include "SpriteAction.h"
class SpAcMove :
	public SpriteAction
{
protected:
	int duration;
	int elapsedTime;
public:
	SpAcMove();
	~SpAcMove();
	void execute();
};
