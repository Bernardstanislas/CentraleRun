#pragma once

#include "Sprite.h"
#include "SpriteType.h"

using namespace std;

class Collider
{
protected:
	SpriteType::Type type1;
	SpriteType::Type type2;
public:
	virtual void collide(pSprite& sp1, pSprite& sp2, Field* target) = 0;
	virtual pair<SpriteType::Type, SpriteType::Type> getSignature() const = 0;
};

typedef std::unique_ptr<Collider> pCollider;