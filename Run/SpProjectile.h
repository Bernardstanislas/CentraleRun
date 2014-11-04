#pragma once
#include "Sprite.h"
class SpProjectile :
	public Sprite
{
public:
	SpProjectile();
	SpProjectile(int x, int y, int width, int height, int state);
	~SpProjectile();
};

