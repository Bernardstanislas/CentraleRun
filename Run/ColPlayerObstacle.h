#pragma once

#include "Collider.h"

class ColPlayerObstacle :
	public Collider
{
public:
	ColPlayerObstacle();

	void collide(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2, Field* target);
	pair<SpriteType::Type, SpriteType::Type> getSignature() const;
};
