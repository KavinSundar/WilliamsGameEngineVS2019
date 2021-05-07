#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Score.h"


GameScene::GameScene() {
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);
}
int GameScene::getScore()
{
	return score_;
}
void GameScene::increaseScore()
{
	++score_;
}
int GameScene::getLives() {
	return lives_;

}
void GameScene::decreaseLives() {
	--lives_;
	if (lives_ == 0) {
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}