#pragma once
#include "SpriteAction.h"
#include "Direction.h"

class SpAcFireProjectile :
	public SpriteAction
{
private:
	int fireRate;
public:
	SpAcFireProjectile(int fireRate = 0);
	FieldAction* execute();
};
