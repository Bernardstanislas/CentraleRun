#pragma once
#include "Sprite.h"
class SpBonus :
	public Sprite
{
public:
    SpBonus();
	SpBonus(int x, int y, int width, int height, int state);
	~SpBonus();
};

