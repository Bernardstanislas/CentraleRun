#pragma once
#include "Sprite.h"
class Obstacle :
	public Sprite
{
protected:
	int hp;
public:
	Obstacle();
	~Obstacle();
};

