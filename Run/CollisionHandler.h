#pragma once

#include <map>
#include "Collider.h"


using namespace std;

typedef pair<SpriteType::Type, SpriteType::Type> ColliderKey;
typedef map<ColliderKey, shared_ptr<Collider>> ColliderMap;

class CollisionHandler
{
private:
	vector<unique_ptr<Collider>> activeColliders;
	vector<unique_ptr<Collider>> inactiveColliders;
	unique_ptr<Collider>& getCollider(const unique_ptr<Sprite>& sp1, const unique_ptr<Sprite>& sp2);
	SpriteType::Type getSpriteType(const unique_ptr<Sprite>& sp) const;
	bool areColliding(const unique_ptr<Sprite>& sp1, const unique_ptr<Sprite>& sp2) const;
	Field* target;
public:
	CollisionHandler(Field* target);
	~CollisionHandler();
	void executeCollider(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2);
};
