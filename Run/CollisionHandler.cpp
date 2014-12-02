#include "CollisionHandler.h"
#include "SpriteType.h"
#include <typeinfo>
#include <iostream>
#include "ColPlayerObstacle.h"


CollisionHandler::CollisionHandler(Field* target) : target(target)
{
	activeColliders = vector<unique_ptr<Collider>>();
	activeColliders.push_back(unique_ptr<Collider>(new ColPlayerObstacle()));
	inactiveColliders = vector<unique_ptr<Collider>>();
}

CollisionHandler::~CollisionHandler()
{

}

void CollisionHandler::executeCollider(unique_ptr<Sprite> &sp1, unique_ptr<Sprite> &sp2)
{
	if (areColliding(sp1, sp2))
	{
		unique_ptr<Collider>& collider = this->getCollider(sp1, sp2);
		//if (collider)
			//collider->collide(sp1, sp2, target);
	}
}

unique_ptr<Collider>& CollisionHandler::getCollider(const unique_ptr<Sprite> &sp1, const unique_ptr<Sprite> &sp2)
{
	const SpriteType::Type type1 = this->getSpriteType(sp1);
	const SpriteType::Type type2 = this->getSpriteType(sp2);
	for(auto& collider : activeColliders)
	{
		const pair<SpriteType::Type, SpriteType::Type> signature = collider->getSignature();
		if ((signature.first == type1 && signature.second == type2) || (signature.first == type2 && signature.second == type1))
			return collider;
	}
	auto null_output = unique_ptr<Collider>(nullptr);
	return null_output;
}

SpriteType::Type CollisionHandler::getSpriteType(const unique_ptr<Sprite> &sp) const
{
	return sp->getType();
}

bool CollisionHandler::areColliding(const unique_ptr<Sprite>& sp1, const unique_ptr<Sprite>& sp2) const
{
	pair<int, int> position1 = sp1->getPosition();
	pair<int, int> position2 = sp2->getPosition();
	pair<int, int> size1 = sp1->getSize();
	pair<int, int> size2 = sp2->getSize();

	// Check if sprite 2 collides in sprite 1 bounding box
	bool horizontal1 = ((position1.first + size1.first) < position2.first) || ((position2.first + size2.first) < position1.first);
	bool vertical1 = ((position1.second + size1.second) < position2.second) || ((position2.second + size2.second) < position1.second);

	// Check if sprite 1 collides in sprite 1 bounding box
	bool horizontal2 = ((position2.first + size2.first) < position1.first) || ((position1.first + size1.first) < position2.first);
	bool vertical2 = ((position2.second + size2.second) < position1.second) || ((position1.second + size1.second) < position2.second);

	return !(horizontal1 || vertical1 || horizontal2 || vertical2);
}
