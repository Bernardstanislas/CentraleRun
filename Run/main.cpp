#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"

#include "View.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Run");
	window.setFramerateLimit(VIEW_FRAMERATE);
	
	View mainView(window);

	int frameSkip = 0;

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

		// View is rocking a VIEW_FRAMERATE framerate (probably 60fps)
		// But we're effectively acting only at a FRAMERATE framerate (meaning we're handling things every 3-4 frame)
		if (frameSkip < VIEW_FRAMERATE / FRAMERATE - 1) frameSkip++;
		else
		{
			mainView.field.executeSpriteActions();
			mainView.field.executeFieldActions();
			frameSkip = 0;
		}

		// Redraw and display current frame
		mainView.draw();
		window.display();
	}
	return 0;
}
