#pragma once
#include "Sprite.h"

class SpBonus :
	public Sprite
{
public:
	const SpriteType::Type getType();
	SpBonus();
};
