#pragma once
#include "SpriteAction.h"
class SpAcFireProjectile :
	public SpriteAction
{
protected:
	int duration;
	int elapsedTime;
public:
	SpAcFireProjectile();
	~SpAcFireProjectile();
	void execute();
};
