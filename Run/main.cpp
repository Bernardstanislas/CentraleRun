#include <SFML/Graphics.hpp>
#include <iostream>

#include "view.h"

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

		// Redraw and display current frame
		mainView.draw();
		window.display();
	}
	return 0;
}
