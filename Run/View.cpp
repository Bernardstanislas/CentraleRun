#include "View.h"
#include "SpPlayer.h"
#include "Sprite.h"
#include "SpObstacle.h"
#include "SpProjectile.h"
#include "SpAcMove.h"
#include "FieldAction.h"
#include "FiAcMove.h"

View::View(sf::RenderWindow &context) : context(context)
{
	// Sample data for testing
	unique_ptr<Sprite> player = unique_ptr<SpPlayer>(new SpPlayer());
	unique_ptr<Sprite> sprite1 = unique_ptr<SpObstacle>(new SpObstacle(3, 3, 6, 1));
	unique_ptr<Sprite> sprite2 = unique_ptr<SpObstacle>(new SpObstacle(2, 2, 8, 2));
	unique_ptr<Sprite> sprite3 = unique_ptr<SpObstacle>(new SpObstacle(5, 2, 10, 0));
	
	unique_ptr<Sprite> proj = unique_ptr<SpProjectile>(new SpProjectile(0, 10));
	unique_ptr<SpriteAction> movement = unique_ptr<SpAcMove>(new SpAcMove(2));
	proj->addAction(movement);

	field.addSprite(player);
	field.addSprite(sprite1);
	field.addSprite(sprite2);
	field.addSprite(sprite3);
	field.addSprite(proj);

	unique_ptr<FieldAction> run = unique_ptr<FiAcMove>(new FiAcMove(1));
	field.addAction(run);
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

		float width = (float)size.first*blockSize;
		float height = (float)size.second*blockSize;

		// Our block origin is bottom-left corner and SMFL's is top-left.
		float x = (float)pos.first*blockSize;
		float y = context.getSize().y - (float)pos.second*blockSize - height;

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
