#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include "SpriteAction.h"
#include "SpriteType.h"

using namespace std;

class Sprite
{
protected:
	int x;
	int y;
	int width;
	int height;
	vector<pair<pSpriteAction,bool>> spActions;
	int state; // Is interpreted for now as a rectangle color. 0 for blue, 1 for red and 2 for green.
public:
	virtual ~Sprite() = default;
	virtual const SpriteType::Type getType() = 0;
	void setPosition(int x, int y);
	pair<int, int> getPosition();
	void setSize(int width, int height);
	pair<int, int> getSize();
	void setState(int state);
	int getState();
	void addAction(pSpriteAction &spActions);
	vector<pFieldAction> executeActions();
	void executeNewActions();
	vector<pair<pSpriteAction,bool>> const& getActions() const;
};

typedef std::unique_ptr<Sprite> pSprite;
