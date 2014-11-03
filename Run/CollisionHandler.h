#pragma once

#include <map>
#include "Collider.h"

using namespace std;

typedef pair<SpriteType::Type, SpriteType::Type> ColliderKey;
typedef map<ColliderKey, shared_ptr<Collider>> ColliderMap;

class CollisionHandler
{
private:
	ColliderMap associationMap;
	vector<shared_ptr<Collider>> knownColliders;
	shared_ptr<Collider> getCollider(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2);
	SpriteType::Type getSpriteType(unique_ptr<Sprite>& sp);
public:
	CollisionHandler();
	~CollisionHandler();
	void executeCollider(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2);
};

