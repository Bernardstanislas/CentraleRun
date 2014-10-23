#pragma once

#include "Sprite.h"
#include "Action.h"

using namespace std;

class Field
{
private:
	vector<shared_ptr<Sprite>> sprites; // Shared because it's shared with the sprite actions
	vector<unique_ptr<Action>> actions;
public:
	Field();
	~Field();

	void addSprite(Sprite &sprite);
	void addAction(Action &action);

	void executeFieldActions();
	void executeSpriteActions();
	void checkCollisions();
	int updateScore();
};
