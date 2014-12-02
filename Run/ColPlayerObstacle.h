#pragma once

#include "Collider.h"

class ColPlayerObstacle :
	public Collider
{
public:
	ColPlayerObstacle();

	void collide(pSprite& sp1, pSprite& sp2, Field* target);
	pair<SpriteType::Type, SpriteType::Type> getSignature() const;
};
