#pragma once

#include <utility>

using namespace std;

class Sprite;

class SpriteView {
private:
	int x;
	int y;
	int width;
	int height;
public:
	Sprite* sprite;
	SpriteView(Sprite* sprite, int width, int height, int x, int y);
	pair<int, int> getPosition();
	pair<int, int> getSize();
};