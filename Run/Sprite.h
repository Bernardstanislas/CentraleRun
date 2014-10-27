#pragma once

#include <vector>
#include <memory>

#include "Action.h"

using namespace std;

class Sprite
{
protected:
	int x;
	int y;
	int width;
	int height;
	vector<unique_ptr<Action>> actions;
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
	void addAction(unique_ptr<Action> &action);
	void deleteAction(unique_ptr<Action> action);
	void executeActions();
};
