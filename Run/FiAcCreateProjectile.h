#pragma once

#include "FieldAction.h"
#include "SpriteType.h"

class FiAcCreateProjectile :
	public FieldAction
{
protected:
	int x;
	int y;
	SpriteType projectile;
public:
	FiAcCreateProjectile(SpriteType projectile, int x, int y);
	void execute();
};
