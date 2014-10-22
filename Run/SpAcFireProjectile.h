#pragma once
#include "SpriteAction.h"
class FireProjectile :
	public SpriteAction
{
protected:
	int duration;
	int elapsedTime;
public:
	FireProjectile();
	~FireProjectile();
	void execute();
};
