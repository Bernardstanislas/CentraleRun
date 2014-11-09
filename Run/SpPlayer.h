#pragma once
#include "Sprite.h"

class SpPlayer :
	public Sprite
{
protected:
	int hp;
public:
	const SpriteType::Type getType();
	SpPlayer();
};
