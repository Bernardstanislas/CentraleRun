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
	pSprite player = unique_ptr<SpPlayer>(new SpPlayer());
	field.addSprite(player);

	pFieldAction run = unique_ptr<FiAcMove>(new FiAcMove());
	field.addAction(run);
	pFieldAction generate = unique_ptr<FiAcGenerate>(new FiAcGenerate());
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
		pair<int, int> size = sprite->getSize();
		int state = sprite->getState();

		vector<SpriteView>::iterator prevSprite = find_if(
			prevSprites.begin(),
			prevSprites.end(),
			[&sprite](SpriteView spriteV)
			{
				return spriteV.sprite == sprite.get();
			});
		pair<int, int> ppos;
		pair<int, int> psize;
		if (prevSprite != prevSprites.end())
		{
			ppos = (*prevSprite).getPosition();
			psize = (*prevSprite).getSize();
		}
		else
		{
			ppos = pos;
			psize = size;
		}

		float width = (psize.first + (size.first - psize.first) * (float)frameSkip / FRAMESKIP) * blockSize;
		float height = (psize.second + (size.second - psize.second) * (float)frameSkip / FRAMESKIP) * blockSize;

		// Our block origin is bottom-left corner and SMFL's is top-left.
		float x = (ppos.first + (pos.first - ppos.first) * (float)frameSkip / FRAMESKIP) * blockSize;
		float y = context.getSize().y - (ppos.second + (pos.second - ppos.second) * (float)frameSkip / FRAMESKIP) * blockSize - height;

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
		
		}
		context.draw(shape);
	}
}
