#pragma once

#include "Sprite.h"

class SpObstacle :
	public Sprite
{
protected:
	int hp;
public:
	SpObstacle(int width, int height, int x, int y);
};

