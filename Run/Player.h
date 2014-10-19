#pragma once
#include "Sprite.h"
class Player :
	public Sprite
{
protected:
	int hp;
public:
	Player();
	~Player();
};

