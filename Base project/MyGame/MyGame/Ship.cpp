#include "Ship.h"
#include "Laser.h"
#include <ctime>
#include <time.h>
#include <iterator>
const float SPEED = 0.3f;
const int FIRE_DELAY = 200;
const int TELE = 1;
void Ship::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))	y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))	y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))	y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))	y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))	x += TELE * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))	x -= TELE * msElapsed;


	int random_numberX = rand() % 50;
	int random_numberY = rand() % 40;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))	x = random_numberX * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))	y = random_numberY * msElapsed;
	
	

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && fireTimer_ <= 0) {
		song.setBuffer(GAME.getSoundBuffer("Resources/Moon Song.wav"));
		song.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && fireTimer_ <= 0) {
		teleportnoise.setBuffer(GAME.getSoundBuffer("Resources/Punch1.wav"));
		teleportnoise.play();
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