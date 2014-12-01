#pragma once

#include "Sprite.h"
#include "CollisionHandler.h"
#include "FieldAction.h"
#include "SpriteView.h"
#include "TerrainSequence.h"
#include "SpObstacle.h"
#include <algorithm>

#include "config.h"

using namespace std;

typedef pair<int, vector<TerrainGrid>> Sequence;

class Field
{
private:
	vector<unique_ptr<Sprite>> sprites;
	vector<unique_ptr<FieldAction>> actions;
	unique_ptr<CollisionHandler> collisionHandler;
	int speed = BASE_SPEED;
	vector<Sequence> sequences;
public:
	Field();
	
	vector<TerrainGrid> getSequence(int complexity);
	unique_ptr<Sprite> MakeRegularBlock(TerrainGrid &block);

	int getSpeed();
	void setSpeed(int speed);
	void incSpeed();

	vector<unique_ptr<Sprite>> const& getSprites() const;
	unique_ptr<Sprite> const& getSprite(unique_ptr<Sprite> &sprite) const;

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
