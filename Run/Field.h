#pragma once

#include "Sprite.h"
#include "Action.h"
#include "CollisionHandler.h"

using namespace std;

class Field
{
private:
	vector<unique_ptr<Sprite>> sprites;
	vector<unique_ptr<Action>> actions;
	CollisionHandler *collisionHandler;

public:
	Field();
	~Field();

	// return in C++ copy the returned object, so we need to return a reference.
	// const's are just there for clarity
	vector<unique_ptr<Sprite>> const& getSprites() const;

	void addSprite(unique_ptr<Sprite> &sprite);
	void addAction(unique_ptr<Action> &action);

	void executeFieldActions();
	void executeSpriteActions();
	void executeCollisions();
	int updateScore();
};
