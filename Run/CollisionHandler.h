#pragma once

#include <map>
#include "Collider.h"

using namespace std;

typedef pair<SpriteType, SpriteType> ColliderKey;
typedef map<ColliderKey, shared_ptr<Collider>> ColliderMap;

class CollisionHandler
{
private:
	ColliderMap associationMap;
	vector<shared_ptr<Collider>> knownColliders;
	shared_ptr<Collider> getCollider(Sprite sp1, Sprite sp2);
	SpriteType getSpriteType(Sprite sp);
public:
	CollisionHandler();
	~CollisionHandler();
	void executeCollider(Sprite sp1, Sprite sp2);
};
