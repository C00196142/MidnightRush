#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(2160, 1440), "SFML works!");

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("Resources/playersheet.png"))
	{
		// error...
	}

	sf::IntRect spriteSource = sf::IntRect(0, 0, 150, 150);

	sf::Sprite playerSprite;
	playerSprite.setTextureRect(spriteSource);
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(200, 200);

	int count = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			spriteSource.left = 0;
			playerSprite.move(0, -0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			spriteSource.left = 150;
			playerSprite.move(0, 0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			spriteSource.left = 450;
			playerSprite.move(-0.1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			spriteSource.left = 300;
			playerSprite.move(0.1, 0);
		}

		playerSprite.setTextureRect(spriteSource);

	/*	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			count = count + 1;
			if (count > 5)
			{
				playerTexture.loadFromFile("playerUpHit.png");
			}
			if (count <= 5)
			{
				playerTexture.loadFromFile("playerUp.png");
				count = 0;
			}
			cout << count << endl;
		}*/

		window.clear();
		window.draw(playerSprite);
		window.display();
	}

	return 0;
}