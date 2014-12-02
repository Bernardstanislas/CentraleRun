#pragma once

#include <map>
#include "Collider.h"

using namespace std;

typedef pair<SpriteType::Type, SpriteType::Type> ColliderKey;
typedef map<ColliderKey, shared_ptr<Collider>> ColliderMap;

class CollisionHandler
{
private:
	vector<pCollider> activeColliders;
	vector<pCollider> inactiveColliders;
	pCollider& getCollider(const pSprite& sp1, const pSprite& sp2);
	SpriteType::Type getSpriteType(const pSprite& sp) const;
	bool areColliding(const pSprite& sp1, const pSprite& sp2) const;
	Field* target;
public:
	CollisionHandler(Field* target);
	~CollisionHandler();
	void executeCollider(pSprite& sp1, pSprite& sp2);
};

typedef std::unique_ptr<CollisionHandler> pCollisionHandler;
