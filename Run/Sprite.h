#pragma once

#include <vector>
#include <memory>

#include "action.h"

using namespace std;

class Sprite
{
protected:
	int x; // block
	int y; // block
	int width; // blocks
	int height; // blocks
	// !!!! Compilation error here!
	//vector<unique_ptr<Action>> actions;
	// !!!!
	int state;
public:
	Sprite();
	Sprite(int x, int y, int width, int height, int state);
	void setPosition(int x, int y);
	pair<int, int> getPosition();
	void setSize(int width, int height);
	pair<int, int> getSize();
	void setState(int state);
	int getState();
	void addAction(Action &action);
	void deleteAction(unique_ptr<Action> action);
	void executeActions();
};
