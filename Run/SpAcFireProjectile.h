#pragma once
#include "SpriteAction.h"

class SpAcFireProjectile :
	public SpriteAction
{
public:
	SpAcFireProjectile();
	FieldAction* execute();
};
