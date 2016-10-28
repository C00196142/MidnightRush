
#include "Menu.h"

Menu::Menu(float base, float height)
{
	// loads in a font
	if (!myFont.loadFromFile("fonts/Shoguns Clan.ttf"))
	{
		// error
	}

	// setting up an index for the buttons in the menu
	buttonIndex = 0;

	// sets up the appropriate variables for the Play Game Button
	buttons[0].setFont(myFont);
	buttons[0].setScale(2.0f, 2.0f);
	buttons[0].setPosition(sf::Vector2f(base / 2.25, height / 3));
	buttons[0].setColor(sf::Color::White);
	buttons[0].setString("Play Game");

	// sets up the appropriate variables for the Options Button
	buttons[1].setFont(myFont);
	buttons[1].setScale(2.0f, 2.0f);
	buttons[1].setPosition(sf::Vector2f(base / 2.25, height / 2));
	buttons[1].setColor(sf::Color::Red);
	buttons[1].setString("Options");

	// sets up the appropriate variables for the Quit Game Button
	buttons[2].setFont(myFont);
	buttons[2].setScale(2.0f, 2.0f);
	buttons[2].setPosition(sf::Vector2f(base /2.25, height / 1.5));
	buttons[2].setColor(sf::Color::Red);
	buttons[2].setString("Quit");


}

Menu::~Menu()
{

}

// Used to iterate upwards through the menu. 
// Note: if you go up to the top of the menu, and then press the Up button, the index will change to the button at the bottom of the menu.
void Menu::Up()
{
	if (buttonIndex == 0)
	{
		buttons[buttonIndex].setColor(sf::Color::Red);
		buttonIndex = 2;
		buttons[buttonIndex].setColor(sf::Color::White);
	}
	else if (buttonIndex == 1)
	{
		buttons[buttonIndex].setColor(sf::Color::Red);
		buttonIndex = 0;
		buttons[buttonIndex].setColor(sf::Color::White);
	}
	else if (buttonIndex == 2)
	{
		buttons[buttonIndex].setColor(sf::Color::Red);
		buttonIndex = 1;
		buttons[buttonIndex].setColor(sf::Color::White);
	}
}

// Used to iterate downwards through the menu.
// Note: if you go down to the bottom of the menu, and then press the Down button, the index will adjust to the button at the top of the menu.
void Menu::Down()
{
	if (buttonIndex == 0)
	{
		buttons[buttonIndex].setColor(sf::Color::Red);
		buttonIndex = 1;
		buttons[buttonIndex].setColor(sf::Color::White);
	}
	else if (buttonIndex == 1)
	{
		buttons[buttonIndex].setColor(sf::Color::Red);
		buttonIndex = 2;
		buttons[buttonIndex].setColor(sf::Color::White);
	}
	else if (buttonIndex == 2)
	{
		buttons[buttonIndex].setColor(sf::Color::Red);
		buttonIndex = 0;
		buttons[buttonIndex].setColor(sf::Color::White);
	}
}

// method for drawing the buttons
void Menu::Draw(sf::RenderWindow &window)
{
	for (int index = 0; index < MAX_NUMBER_OF_MENU_BUTTONS; index++)
	{
		window.draw(buttons[index]);
	}
}