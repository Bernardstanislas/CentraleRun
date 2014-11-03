#pragma once

#define BLOCKSIZE 30

#include <SFML/Graphics.hpp>
#include "Field.h"

class View
{
private:
	sf::RenderWindow& context;
	Field field;
	int blockSize = BLOCKSIZE;
public:
	View(sf::RenderWindow &context);
	~View();
	void draw();
};

