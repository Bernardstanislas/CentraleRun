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
	virtual void collide(Sprite sp1, Sprite sp2) = 0;
	pair<SpriteType::Type, SpriteType::Type> getSignature();
};

