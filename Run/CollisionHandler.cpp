#include "CollisionHandler.h"
#include "SpriteType.h"
#include <typeinfo>


CollisionHandler::CollisionHandler() {
  knownColliders = vector<shared_ptr<Collider>>();
};

CollisionHandler::~CollisionHandler() {

};

void CollisionHandler::executeCollider(unique_ptr<Sprite> &sp1, unique_ptr<Sprite> &sp2) {
  if (colliding(sp1, sp2)) {
    shared_ptr<Collider> collider = this->getCollider(sp1, sp2);
    collider->collide(sp1, sp2);
  }
};

shared_ptr<Collider> CollisionHandler::getCollider(unique_ptr<Sprite> &sp1, unique_ptr<Sprite> &sp2) {
  SpriteType::Type type1 = this->getSpriteType(sp1);
  SpriteType::Type type2 = this->getSpriteType(sp2);
  ColliderKey pair1(type1, type2);
  ColliderKey pair2(type2, type1);
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

SpriteType::Type CollisionHandler::getSpriteType(unique_ptr<Sprite> &sp) {
  string sType = typeid(sp).name();
  return SpriteType::getType(sType);
};

bool CollisionHandler::colliding(unique_ptr<Sprite>& sp1, unique_ptr<Sprite>& sp2) {
  pair<int, int> position1 = sp1->getPosition();
  pair<int, int> position2 = sp2->getPosition();
  pair<int, int> size1 = sp1->getSize();
  pair<int, int> size2 = sp2->getSize();

  // Check if sprite 2 collides in sprite 1 bounding box
  bool horizontal1 = position1.first + size1.first < position2.first && position2.first + size2.first < position1.first;
  bool vertical1 = position1.second + size1.second < position2.second && position2.second + size2.second < position1.second;

  // Check if sprite 1 collides in sprite 1 bounding box
  bool horizontal2 = position2.first + size2.first < position1.first && position1.first + size1.first < position2.first;
  bool vertical2 = position2.second + size2.second < position1.second && position1.second + size1.second < position2.second;

  return !(horizontal1 && vertical1 && horizontal2 && vertical2);
}
