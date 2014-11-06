#pragma once

#include "config.h"

#include <SFML/Graphics.hpp>
#include "Field.h"

class View
{
private:
	sf::RenderWindow& context;
	int blockSize = BLOCKSIZE;
public:
	Field field;
	View(sf::RenderWindow &context);
	void draw();
};

