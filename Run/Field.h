#pragma once

#include "Sprite.h"
#include "CollisionHandler.h"
#include "FieldAction.h"
#include <algorithm>

using namespace std;

class Field
{
private:
	vector<unique_ptr<Sprite>> sprites;
	vector<unique_ptr<FieldAction>> actions;
	unique_ptr<CollisionHandler> collisionHandler;

public:
	Field();
	// return in C++ copy the returned object, so we need to return a reference.
	// const's are just there for clarity
	vector<unique_ptr<Sprite>> const& getSprites() const;
	vector<Sprite*> getSpritesCopy();

	void addSprite(unique_ptr<Sprite> &sprite);
	void deleteSprite(unique_ptr<Sprite> &sprite);
	void deleteOutOfBoundSprites();
	void addAction(unique_ptr<FieldAction> &action);
	void deleteAction(unique_ptr<FieldAction> &action);

	void executeFieldActions();
	void executeSpriteActions();
	void executeCollisions();
	int updateScore();
};
