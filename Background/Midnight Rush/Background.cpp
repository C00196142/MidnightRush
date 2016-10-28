#include "Background.h"
#include <iostream>

Background::Background()
{
	// load in the sprite sheet for use
	if (!levelTexture.loadFromFile("Sprites Folder/levelTexture.png"))
	{
		// error...
	}

	// set up a shared pointer holding the number of levels
	levelCount = std::shared_ptr<int>(new int(0));

	// Basically, if it's the first level, it will go by the following parameters
	if (*levelCount == 0)
	{
		maxRow = 12;
		maxCol = 14;
		pMap = (int*)map;
	}
	CreateMap();
}

// method for drawing the tiles/sprites from the sprite vector for the background
void Background::Draw(sf::RenderWindow *window)
{
	for (int i = 0; i < maxSquares; i++)
	{
		window->draw(spriteVector[i]);
	}
}

// from this method we can create a map
void Background::CreateMap()
{
	// finds out the maximum amount of tiles on the map
	maxSquares = maxRow * maxCol;
	// 
	for (int i = 0; i < maxSquares; i++)
	{
		// Adds a new sprite at the end of the vector, after its current last element. 
		spriteVector.push_back(sf::Sprite());
		// then, we set its texture and and the scale
		// I would have to set the position of the sprite sheet (off of the screen), if I didn''t make sure that ALL of the parts of the map were assigned
		spriteVector[i].setTexture(levelTexture);
		spriteVector[i].setScale(0.5f, 0.5f);
	}
	int index = 0;
	for (int column = 0; column < maxCol; column++)
	{
		for (int row = 0; row < maxRow; row++)
		{
			if (pMap[maxCol*(row)+column] == 1) // Hallway
			{
				// extracts a sprite from a particular section of a sprite sheet 
				spriteVector[index].setTextureRect(sf::IntRect(0, 0, 168, 168)); // Rect (T rectLeft, T rectTop, T rectWidth, T rectHeight)
				// sets the position of a sprite in the sprite index
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}

			if (pMap[maxCol*(row)+column] == 2) // Rotated Hallway
			{
				// extracts a sprite from a particular section of a sprite sheet
				spriteVector[index].setTextureRect(sf::IntRect(0, 0, 168, 168));
				// rotation of the sprite is performed here
				spriteVector[index].setOrigin(84, 84);
				RotateImage(-90, index);
				spriteVector[index].setOrigin(168, 0);
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);				
				index++;
			}

			if (pMap[maxCol*(row)+column] == 3) // Floor
			{
				// extracts a sprite from a particular section of a sprite sheet 
				spriteVector[index].setTextureRect(sf::IntRect(168, 0, 168, 168));
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}
		}
	}
}

// can be used to rotate a sprite from the sprite vector
void Background::RotateImage(int degrees, int index)
{
	spriteVector[index].setOrigin(sf::Vector2f(45.5, 45.5));
	spriteVector[index].setRotation(degrees);
	spriteVector[index].setOrigin(sf::Vector2f(0, 0));
}

// the assigned layout of the first map
// operates on values assigned to pMap in CreateMap() method
const int Background::map[12][14]
{
	// 12 rows, 14 columns
	// this will altered so that we actually have a usable map
	{ 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
	{ 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
	{ 2, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2 },
	{ 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2 },
	{ 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2 },
	{ 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2 },
	{ 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 }
};

// method so we can easily return the level we are on
std::shared_ptr<int> Background::getMapCount()
{
	return levelCount;
}