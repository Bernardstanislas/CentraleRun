#include "View.h"
#include "Sprite.h"

View::View(sf::RenderWindow &context) : context(context)
{
	// Sample data for testing
	auto sprite1 = make_shared<Sprite>(10, 10, 10, 10, 0);
	auto sprite2 = make_shared<Sprite>(30, 20, 5, 5, 1);
	auto sprite3 = make_shared<Sprite>(50, 50, 2, 5, 2);

	field.addSprite(sprite1);
	field.addSprite(sprite2);
	field.addSprite(sprite3);
}


View::~View()
{
}

// Draw all sprites from the field as colored rectangles.
void View::draw()
{
	context.clear(sf::Color::Black);

	for (auto sprite : field.getSprites())
	{
		pair<int, int> pos = sprite.get()->getPosition();
		pair<int, int> size = sprite.get()->getSize();
		int state = sprite.get()->getState();
		
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