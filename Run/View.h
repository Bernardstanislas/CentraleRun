#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"

class View
{
private:
	sf::RenderWindow& context;
	Field field;
	int blockSize = 10;
public:
	View(sf::RenderWindow &context);
	~View();
	void draw();
};

