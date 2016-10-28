/////////////////////////////////////////
////// Contributors: Kevin Boylan
//////
////// Method for loading in a menu
////// Started: 25/10/2016
//////////////////////////////////////////


#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_MENU_BUTTONS 3

class Menu
{
public:

	int buttonIndex = 0;
	Menu(float base, float height); // for menu window
	~Menu();

	void Up();
	void Down();
	int useMenuButtons() { return buttonIndex; }
	void Draw(sf::RenderWindow &window);

private:
	sf::Text buttons[MAX_NUMBER_OF_MENU_BUTTONS];
	sf::Font myFont;
};