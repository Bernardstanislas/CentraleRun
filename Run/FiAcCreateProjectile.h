#pragma once

#include "FieldAction.h"
#include "SpriteType.h"
#include "Direction.h"

class FiAcCreateProjectile :
	public FieldAction
{
protected:
	int x;
	int y;
	Direction direction;
public:
	FiAcCreateProjectile(int x, int y, Direction direction = Direction::RIGHT);
	void execute();
};
