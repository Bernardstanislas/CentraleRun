#pragma once

#include "FieldAction.h"
#include "SpriteType.h"

class FiAcCreateProjectile :
	public FieldAction
{
protected:
	int x;
	int y;
public:
	FiAcCreateProjectile(int x, int y);
	void execute();
};
