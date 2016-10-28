#include "SFML/Graphics.hpp" 
#include "Background.h"
#include <iostream>
#include <memory>

Background background;

int main()
{
	// sets the size of the window
	sf::RenderWindow window(sf::VideoMode(1980, 1080), "Midnight Rush");
													  
	while (window.isOpen())
	{
		window.clear();
		background.Draw(&window);
		window.display(); 
	}
}

