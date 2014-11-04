#pragma once
#include "Sprite.h"
class SpPlayer :
	public Sprite
{
protected:
	int hp;
public:
	SpPlayer();
	SpPlayer(int x, int y, int width, int height, int state);
	~SpPlayer();
};

