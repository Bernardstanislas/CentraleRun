#include <SFML/Graphics.hpp>
#include <iostream>

#include "View.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Run");
	View mainView(window);

	while (window.isOpen())
	{
		// Handle window closing
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		mainView.field.executeSpriteActions();
		mainView.field.executeFieldActions();
		// Redraw and display current frame
		mainView.draw();
		window.display();
		sf::sleep(sf::seconds(.1f));
	}
	return 0;
}
