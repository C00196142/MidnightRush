//#include "Player.h"
//
//
//Player::Player()
//{
//
//}
//
//
//Player::~Player()
//{
//}
//
//sf::Sprite Player::CreatePlayer(sf::Sprite sprite, sf::Texture* texture)
//{
//	texture->loadFromFile("Resources/playersheet.png");
//	sprite.setTexture(*texture);
//	return sprite;
//
//	playerSprite.setTextureRect(spriteSource);
//	playerSprite.setTexture(playerTexture);
//	playerSprite.setPosition(200, 200);
//}
//
//sf::Sprite Player::GetSprite()
//{
//	return playerSprite;
//}
//
//void Player::Move()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//	{
//		spriteSource.left = 0;
//		playerSprite.move(0, -0.1);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//	{
//		spriteSource.left = 150;
//		playerSprite.move(0, 0.1);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	{
//		spriteSource.left = 450;
//		playerSprite.move(-0.1, 0);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	{
//		spriteSource.left = 300;
//		playerSprite.move(0.1, 0);
//	}
//}
//
//void Player::drawSprite(sf::RenderWindow *window) 
//{
//	window->draw(playerSprite);
//}