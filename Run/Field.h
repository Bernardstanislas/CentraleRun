#pragma once

#include "Sprite.h"
#include "Action.h"
#include "CollisionHandler.h"

using namespace std;

class Field
{
private:
	vector<shared_ptr<Sprite>> sprites; // Shared because it's shared with the sprite actions
	vector<unique_ptr<Action>> actions;
	CollisionHandler *collisionHandler;

public:
	Field();
	~Field();

	vector<shared_ptr<Sprite>> getSprites();

	void addSprite(shared_ptr<Sprite> &sprite);
	void addAction(unique_ptr<Action> &action);

	void executeFieldActions();
	void executeSpriteActions();
	void executeCollisions();
	int updateScore();
};
