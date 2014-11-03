#include "CollisionHandler.h"
#include "SpriteType.h"
#include <typeinfo>

CollisionHandler::CollisionHandler()
{
  knownColliders = vector<shared_ptr<Collider>>();
};

CollisionHandler::~CollisionHandler()
{

};

void CollisionHandler::executeCollider(Sprite sp1, Sprite sp2)
{
  shared_ptr<Collider> collider = this->getCollider(sp1, sp2);
  collider->collide(sp1, sp2);
};

shared_ptr<Collider> CollisionHandler::getCollider(Sprite sp1, Sprite sp2) {
  SpriteType type1 = this->getSpriteType(sp1);
  SpriteType type2 = this->getSpriteType(sp2);
  ColliderKey pair1 (type1, type2);
  ColliderKey pair2 (type2, type1);
  ColliderMap::iterator it;
  it = this->associationMap.find(pair1);
  if (it != this->associationMap.end()) {
    return it->second;
  } else {
    it = this->associationMap.find(pair2);
    if (it != this->associationMap.end()) {
      return it->second;
    } else {
      return shared_ptr<Collider>();
    }
  }
};

SpriteType::Type getSpriteType(Sprite sp) {
  string sType = typeid(sp).name();
  return SpriteType::getType(sType);
};
