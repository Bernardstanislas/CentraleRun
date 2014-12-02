#include "View.h"
#include "SpPlayer.h"
#include "Sprite.h"
#include "SpObstacle.h"
#include "SpProjectile.h"
#include "SpAcMove.h"
#include "SpAcJump.h"
#include "FieldAction.h"
#include "FiAcMove.h"
#include "FiAcGenerate.h"

#include "config.h"

#include <iostream>

#define FRAMESKIP (VIEW_FRAMERATE/FRAMERATE)

View::View(sf::RenderWindow &context) : context(context)
{
	// Sample data for testing
	pSprite player = make_unique<SpPlayer>();
	field.addSprite(player);

	pFieldAction run = make_unique<FiAcMove>();
	field.addAction(run);
	pFieldAction generate = make_unique<FiAcGenerate>();
	field.addAction(generate);
}

// Draw all sprites from the field as colored rectangles.
void View::draw()
{
	context.clear(sf::Color::Black);

	// Iterators copy the objects in vector, so we also need to iterate through references
	for (auto const& sprite : field.getSprites())
	{
		pair<int, int> pos = sprite->getPosition();
		pair<int, int> npos = sprite->getNPosition();

		pair<int, int> size = sprite->getSize();
		int state = sprite->getState();

		float width = size.first * blockSize;
		float height = size.second * blockSize;

		// Our block origin is bottom-left corner and SMFL's is top-left.
		float x = (pos.first + (npos.first - pos.first) * (float)frameSkip / FRAMESKIP) * blockSize;
		float y = context.getSize().y - (pos.second + (npos.second - pos.second) * (float)frameSkip / FRAMESKIP) * blockSize - height;

		sf::RectangleShape shape(sf::Vector2f(width, height));
		shape.setPosition(sf::Vector2f(x,y));
		switch (state)
		{
		case 0:
			shape.setFillColor(sf::Color::Blue);
			break;
		case 1:
			shape.setFillColor(sf::Color::Green);
			break;
		case 2:
			shape.setFillColor(sf::Color::Red);
			shape.setSize(sf::Vector2f(shape.getSize().x, shape.getSize().y / 4));
			break;
		case 3:
			shape.setFillColor(sf::Color::Red);
			shape.setSize(sf::Vector2f(shape.getSize().x / 4, shape.getSize().y));
			break;
		case 4:
			shape.setFillColor(sf::Color::Red);
			break;
		}

		context.draw(shape);
	}
}
