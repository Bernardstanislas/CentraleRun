#pragma once
#include "Sprite.h"
class SpObstacle :
	public Sprite
{
protected:
	int hp;
public:
	SpObstacle();
	SpObstacle(int x, int y, int width, int height, int state);
	~SpObstacle();
};

