#pragma once
#include "SpriteAction.h"
class SpAcMove :
	public SpriteAction
{
protected:
	int speed;
	int vspeed;
	int loopTime;
public:
	SpAcMove(int speed, int vspeed = 0, int loopTime = 0);
	FieldAction* execute();
};
