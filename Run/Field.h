#pragma once

#include "Sprite.h"
#include "CollisionHandler.h"
#include "FieldAction.h"
#include "SpriteView.h"
#include <algorithm>

#include "config.h"

using namespace std;

class Field
{
private:
	vector<unique_ptr<Sprite>> sprites;
	vector<unique_ptr<FieldAction>> actions;
	unique_ptr<CollisionHandler> collisionHandler;
	int speed = BASE_SPEED;
public:
	Field();
	
	int getSpeed();
	void setSpeed(int speed);

	vector<unique_ptr<Sprite>> const& getSprites() const;
	vector<SpriteView> getSpritesView();

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
