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

void CollisionHandler::executeCollider(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2)
{
  shared_ptr<Collider> collider = this->getCollider(sp1, sp2);
  collider->collide(sp1, sp2);
};

shared_ptr<Collider> CollisionHandler::getCollider(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2) {
  SpriteType::Type type1 = this->getSpriteType(sp1);
  SpriteType::Type type2 = this->getSpriteType(sp2);
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

SpriteType::Type CollisionHandler::getSpriteType(unique_ptr<Sprite>& sp) {
  string sType = typeid(sp).name();
  return SpriteType::getType(sType);
};
