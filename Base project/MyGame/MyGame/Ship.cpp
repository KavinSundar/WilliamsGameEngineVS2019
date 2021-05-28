#include "Ship.h"
#include "Laser.h"
#include <ctime>
#include <time.h>
#include <iterator>
const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

void Ship::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))y += SPEED * msElapsed;
	sprite_.setPosition(sf::Vector2f(x, y));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0) {
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);
		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && fireTimer_ <= 0) {
		song2.setBuffer(GAME.getSoundBuffer("Resources/SONG 2.wav"));
		song2.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && fireTimer_ <= 0) {
		song_.setBuffer(GAME.getSoundBuffer("Resources/Song 1.wav"));
		song_.play();
	}
}

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
	

}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}