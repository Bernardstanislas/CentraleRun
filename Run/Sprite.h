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
	int nx; // Actions will modify these ones
	int ny; // And they'll replace the other ones at each frame+1
	int width;
	int height;
	vector<pSpriteAction> spActions;
	int state; // Is interpreted for now as a rectangle color. 0 for blue, 1 for green and 2/3 for red projectiles
public:
	virtual ~Sprite() = default;

	virtual const SpriteType::Type getType() = 0;

	void setPosition(int x, int y);
	pair<int, int> getPosition();

	void setNPosition(int nx, int ny);
	pair<int, int> getNPosition();

	void applyPosition();

	void setSize(int width, int height);
	pair<int, int> getSize();

	void setState(int state);
	int getState();

	void addAction(pSpriteAction &spActions);
	vector<pFieldAction> executeActions();

	vector<pSpriteAction> const& getActions() const;
};

typedef std::unique_ptr<Sprite> pSprite;
