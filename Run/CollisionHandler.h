#pragma once

#include <map>
#include "Collider.h"

using namespace std;

class CollisionHandler
{
private:
	map<pair<SpriteType, SpriteType>, shared_ptr<Collider>> associationMap;
	vector<shared_ptr<Collider>> knownColliders;
public:
	CollisionHandler();
	~CollisionHandler();
	void executeCollider(Sprite sp1, Sprite sp2);
};
