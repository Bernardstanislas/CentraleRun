#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include "Action.h"
#include "FieldAction.h"
#include "SpriteAction.h"

using namespace std;

class Sprite
{
protected:
	int x;
	int y;
	int width;
	int height;
	vector<unique_ptr<SpriteAction>> spActions;// = vector<unique_ptr<Action>>();;
	int state; // Is interpreted for now as a rectangle color. 0 for blue, 1 for red and 2 for green.
public:
	Sprite();
	// Temporary Sprite constructor for testing purposes, won't be used as such.
	Sprite(int x, int y, int width, int height, int state);
	void setPosition(int x, int y);
	pair<int, int> getPosition();
	void setSize(int width, int height);
	pair<int, int> getSize();
	void setState(int state);
	int getState();
	void addAction(unique_ptr<SpriteAction> &spAction);
	void deleteAction(unique_ptr<SpriteAction> spAction);
	vector<unique_ptr<FieldAction>> executeActions();
};
