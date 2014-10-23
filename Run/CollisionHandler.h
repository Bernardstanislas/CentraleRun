#pragma once

#include <map>
#include "Collider.h"

using namespace std;

class CollisionHandler
{
private:
	static CollisionHandler* instance;
	map<pair<SpriteType, SpriteType>, shared_ptr<Collider>> associationMap;
	vector<shared_ptr<Collider>> knownColliders;
	CollisionHandler();
	~CollisionHandler();
public:
	static CollisionHandler* Instance()
	{
		if (NULL == instance)
			instance = new CollisionHandler();

		return instance;
	};
	void executeCollider(Sprite sp1, Sprite sp2);
};

