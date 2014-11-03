#pragma once

#include "Sprite.h"
#include "CollisionHandler.h"
#include "FieldAction.h"

using namespace std;

class Field
{
private:
	vector<unique_ptr<Sprite>> sprites;
	vector<unique_ptr<FieldAction>> actions;
	CollisionHandler *collisionHandler;

public:
	// return in C++ copy the returned object, so we need to return a reference.
	// const's are just there for clarity
	vector<unique_ptr<Sprite>> const& getSprites() const;

	void addSprite(unique_ptr<Sprite> &sprite);
	void deleteSprite(int position);
	void addAction(unique_ptr<FieldAction> &action);
	void deleteAction(int position);

	void executeFieldActions();
	void executeSpriteActions();
	void executeCollisions();
	int updateScore();
};
