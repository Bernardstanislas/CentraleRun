#pragma once
#include "Sprite.h"
class SpObstacle :
	public Sprite
{
protected:
	int hp;
public:
	SpObstacle();
	~SpObstacle();
};

