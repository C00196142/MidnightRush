/////////////////////////////////////////
////// Contributors: Kevin Boylan
//////
////// Used to load in a background, consisting of tiles/sprites (easier to create and customize the maps)
////// Started: 25/10/2016
//////////////////////////////////////////

#include "SFML/Graphics.hpp" 
#include <memory>

class Background 
{
public:
	Background();
	int *pMap;
	void CreateMap();
	void Background::RotateImage(int degrees, int index);
	void Draw(sf::RenderWindow *window);
	std::shared_ptr<int> getMapCount();

	// I'll need to add in a method for changing the map

private:
	// parameters necessary for the maps
	int maxRow;
	int maxCol;
	int maxSquares;

	// for the first map
	static const int map[12][14];

	sf::Texture levelTexture;
	// shared pointer holding the levels
	std::shared_ptr<int> levelCount;
	// sets up a vector for sprites
	std::vector<sf::Sprite> spriteVector;
};
