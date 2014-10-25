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

	void addSprite(Sprite &sprite);
	void addAction(Action &action);

	void executeFieldActions();
	void executeSpriteActions();
	void executeCollisions();
	int updateScore();
};
