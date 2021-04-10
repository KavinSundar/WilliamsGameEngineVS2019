#include "Engine/GameEngine.h"
#include "GameScene.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const std::string WINDOW_TITLE = "Desolation";

#pragma once

#include <set>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class GameObject
{
	public:
		void assignTag(std::string tag);
		bool hasTag(std::string tag);

		bool isDead();
		void makeDead();
		virtual void update(sf::Time& elasped) {}
		virtual void draw(){}
		bool isCollisionCheckEnabled();
		void setCollisionCheckEnabled(bool isCollisionCheckEnabled);
		virtual sf::FloatRect getCollisionRect() { return sf::FloatRect(); }
		virtual void handleEvent (sf::Event& event){}

	private:
		std::set<std::string> tags_;

		bool isDead_ = false;
		bool isCollisionCheckEnabled_ = false;


};
typedef std::shared_ptr<GameObject> GameObjectPtr;
int main()
{
	// Seed the random number generator.
	srand((int)time(NULL));

	// Initialize the game.
	GAME.initialize(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	// Create our scene.
	GameScenePtr scene = std::make_shared<GameScene>();
	GAME.setScene(scene);

	// Run the game loop.
	GAME.run();

	return 0;
}
