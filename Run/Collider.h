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
	virtual void collide(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2, Field* target) = 0;
	virtual pair<SpriteType::Type, SpriteType::Type> getSignature() const = 0;
};
