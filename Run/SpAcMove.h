#pragma once
#include "SpriteAction.h"
class SpAcMove :
	public SpriteAction
{
protected:
	int speed;
public:
	SpAcMove(int speed);
	FieldAction* execute();
};
