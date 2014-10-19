#pragma once

#include <vector>
#include <memory>

#include "action.h"

using namespace std;

class Sprite
{
protected:
	int x; // pixels
	int y; // pixels
	int width; // blocks
	int height; // blocks
	vector<unique_ptr<Action>> actions;
public:
	Sprite();
	Sprite(int width, int height);
	~Sprite();
	void position(int x, int y);
	pair<int, int> position();
	void size(int width, int height);
	pair<int, int> size();
	void addAction(Action &action);
	void executeActions();
};

