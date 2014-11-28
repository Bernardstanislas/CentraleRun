#pragma once
#include "Sprite.h"

class SpProjectile :
	public Sprite
{
public:
	const SpriteType::Type getType();
	SpProjectile(int x, int y, int state);
};
