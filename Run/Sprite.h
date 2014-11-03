#pragma once

#include <vector>
#include <memory>

#include "SpriteAction.h"

using namespace std;

class Sprite
{
protected:
	int x;
	int y;
	int width;
	int height;
	vector<unique_ptr<SpriteAction>> actions;
	int state; // Is interpreted for now as a rectangle color. 0 for blue, 1 for red and 2 for green.
public:
	void setPosition(int x, int y);
	pair<int, int> getPosition();
	void setSize(int width, int height);
	pair<int, int> getSize();
	void setState(int state);
	int getState();
	void addAction(unique_ptr<SpriteAction> action);
	void deleteAction(int position);
	void executeActions();
	vector<unique_ptr<SpriteAction>> const& getActions() const;
};
