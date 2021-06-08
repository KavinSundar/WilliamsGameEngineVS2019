#include "Meteor.h"
#include "Explosion.h"
#include "GameScene.h"
#include "Score.h"


const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	sprite2_.setTexture(GAME.getTexture("Resources/meteor2.png"));
	sprite2_.setPosition(pos);
	assignTag("meteor");
	assignTag("meteor2");
	bool gold = false;;
}
void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed)
{
	int g = rand() % 7;

	if (g == 0) {
		bool gold = true;
	}
	

	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();



	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		punch.setBuffer(GAME.getSoundBuffer("Resources/Punch1.wav"));
		punch.play();
		scene.decreaseLives();
		makeDead();
		
	}
	else {
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		sf::Vector2f pos = sprite_.getPosition();
		otherGameObject.makeDead();
		ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(pos));
		GAME.getCurrentScene().addGameObject(explosion);

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
	}
	makeDead();
}