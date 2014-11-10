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
#include "FiAcCreateProjectile.h"

#include "config.h"

#include <iostream>

#define FRAMESKIP (VIEW_FRAMERATE/FRAMERATE)

View::View(sf::RenderWindow &context) : context(context)
{
	// Sample data for testing
	unique_ptr<Sprite> player = unique_ptr<SpPlayer>(new SpPlayer());

	//Those two lines should replace the manual generation of the projectile for testing, but projectile doest not appear.
	//unique_ptr<FieldAction> createdProj = unique_ptr<FiAcCreateProjectile>(new FiAcCreateProjectile(0,10));
	//field.addAction(createdProj);

	unique_ptr<Sprite> proj = unique_ptr<SpProjectile>(new SpProjectile(0, 10));
	unique_ptr<SpriteAction> movement = unique_ptr<SpAcMove>(new SpAcMove(5));
	proj->addAction(movement);

	field.addSprite(player);
	field.addSprite(proj);

	unique_ptr<FieldAction> run = unique_ptr<FiAcMove>(new FiAcMove(BASE_SPEED));
	field.addAction(run);
	unique_ptr<FieldAction> generate = unique_ptr<FiAcGenerate>(new FiAcGenerate(BASE_SPEED));
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
			shape.setFillColor(sf::Color::Red);
			break;
		case 2:
			shape.setFillColor(sf::Color::Green);
			break;
		}
		context.draw(shape);
	}
}
