#pragma once
#include "SpriteAction.h"
#include "Direction.h"

class SpAcFireProjectile :
	public SpriteAction
{
private:
	int fireRate;
	Direction direction;
public:
	SpAcFireProjectile(Direction direction = Direction::RIGHT, int fireRate = 0);
	FieldAction* execute();
};
