#pragma once

#include "Sprite.h"

class SpEnemy :
	public Sprite
{
protected:
	int hp;
public:
    SpEnemy();
    SpEnemy(int x, int y, int width, int height, int state);
    ~SpEnemy();
};
