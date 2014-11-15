#pragma once

#include "Sprite.h"

class SpObstacle :
	public Sprite
{
protected:
	int hp;
public:
	const SpriteType::Type getType();
	SpObstacle(int width, int height, int x, int y);
	SpObstacle(int width, int height);
};
