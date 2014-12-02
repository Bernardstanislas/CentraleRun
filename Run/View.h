#pragma once

#include "config.h"

#include <SFML/Graphics.hpp>
#include "Field.h"
#include <vector>

class View
{
private:
	sf::RenderWindow& context;
	int blockSize = BLOCKSIZE;
public:
	Field field;
	int frameSkip = 0;
	View(sf::RenderWindow &context);
	void draw();
};

