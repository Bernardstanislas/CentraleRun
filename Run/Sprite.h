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
	vector<unique_ptr<Action>> actions;
public:
	Sprite();
	Sprite(int width, int height);
	~Sprite();
	void setPosition(int x, int y);
	pair<int, int> getPosition();
	void setSize(int width, int height);
	pair<int, int> getSize();
	void addAction(Action &action);
	void deleteAction(unique_ptr<Action> action);
	void executeActions();
};
