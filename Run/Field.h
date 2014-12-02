#pragma once

#include "Sprite.h"
#include "CollisionHandler.h"
#include "FieldAction.h"
#include "TerrainSequence.h"
#include "SpObstacle.h"
#include <algorithm>

#include "config.h"

using namespace std;

typedef pair<int, vector<TerrainGrid>> Sequence;

class Field
{
private:
	vector<pSprite> sprites;
	vector<pFieldAction> actions;
	pCollisionHandler collisionHandler;
	int speed = BASE_SPEED;
	vector<Sequence> sequences;
public:
	Field();
	
	vector<TerrainGrid> getSequence(int complexity);
	pSprite MakeRegularBlock(TerrainGrid &block);

	int getSpeed();
	void setSpeed(int speed);
	void incSpeed();

	vector<pSprite> const& getSprites() const;

	void addSprite(pSprite &sprite);
	void deleteSprite(pSprite &sprite);
	void deleteOutOfBoundSprites();
	void applySpritesPosition();

	void addAction(pFieldAction &action);
	void deleteAction(pFieldAction &action);

	void executeFieldActions();
	void executeSpriteActions();
	void executeCollisions();
	int updateScore();
};
