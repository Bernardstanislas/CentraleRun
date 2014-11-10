#include "ColPlayerObstacle.h"
#include <iostream>

ColPlayerObstacle::ColPlayerObstacle() 
{
	this->type1 = SpriteType::Type::PLAYER;
	this->type2 = SpriteType::Type::OBSTACLE;
}

void ColPlayerObstacle::collide(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2) 
{

}

pair<SpriteType::Type, SpriteType::Type> ColPlayerObstacle::getSignature() const
{
	return pair<SpriteType::Type, SpriteType::Type>(this->type1, this->type2);
}
