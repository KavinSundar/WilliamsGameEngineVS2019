#pragma once

#include "Engine/GameEngine.h"

class Ship : public GameObject
{
public:

	Ship();
	void draw();

private:
	sf::Sprite sprite_;


};
typedef std::shared_ptr<Ship> ShipPtr;






