#include "SFML/Graphics.hpp" 
#include "SFML/Audio.hpp"
#include "Background.h"
#include "Menu.h"
#include "GameState.h"
#include <iostream>
#include <memory>

Background background;

int main()
{
	// sets the size of the window
	sf::RenderWindow window(sf::VideoMode(1980, 1080), "Midnight Rush");
	// finds the size of the x and y axis, for the menu
	Menu menu(window.getSize().x, window.getSize().y); 
													  
	window.setFramerateLimit(60);  // sets the framerate limit at 60FPS
	float timer = 0;  // this timer is for allowing the player to go through the menus when holding down the button
					  // at a reasonabe pace

	// the initial game state
	GameStates presentGameState = GameStates::Main;

	// used for the background music
	sf::Music menuMusic;
	
	// specifies background music
	// we'll have to change this music, as it's copyrighted
	if (!menuMusic.openFromFile("Music/Sweet_Dreams_Are_Made_Of_This_Eurythmics_Lyrics.ogg"))
	{
		//error
		std::cout << "Music not Loaded" << std::endl;
	}

	// the music above will play once the game begins
	menuMusic.play();


	while (window.isOpen())
	{
		// makes sure that the timer is always increasing 
		timer++;
		
		// for if the main menu is the present game state
		if (GameStates::Main == presentGameState)
		{
			if (timer > 15)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (menu.buttonIndex == 0)
					{
						presentGameState = GameStates::Play;
						timer = 0; // resets timer to 0
					}

					if (menu.buttonIndex == 1)
					{
						presentGameState = GameStates::Options;
						timer = 0; // resets timer to 0
					}

					if (menu.buttonIndex == 2)
					{
						// stops the music
						menuMusic.stop();
						// closes the window, as this is  for the "Quit" button
						window.close(); 
						timer = 0; // resets timer to 0
					}
					// clears the window, as we'll be moving to a new game state
					window.clear();
				}

				// if we press up on the keyboard
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					// calls the Up() method
					menu.Up();
					timer = 0; // resets timer to 0
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					menu.Down();
					timer = 0; // resets timer to 0
				}
			}
		}

		//window.clear();

		// if the present game state is Main, we will draw the main menu
		if (presentGameState == GameStates::Main)
		{
			menu.Draw(window);
		}

		// if the present game state is Play, we will draw the background
		if (presentGameState == GameStates::Play)
		{
			background.Draw(&window);
		}
		window.display(); 
	}
}

