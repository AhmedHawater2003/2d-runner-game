#include "GameManager.h"

GameManager::GameManager(double gameHeight, double gameWidth){
	gameState = new GameState(0, 5, gameWidth, gameHeight, 100, gameHeight - 100, 3);
	lowerSection = new GameLowerSection(gameState, gameState->getLowerBound());
	upperSection = new GameUpperSection(gameState, gameHeight - gameState->getUpperBound());

	player = new Player({ 10, gameState->getLowerBound() }, gameState->getLowerBound());

	flowManager = new FlowManager(gameState, &obstacles, &collectables);
	collesionManager = new CollesionManager(player, gameState ,&obstacles, &collectables);
	flowManager->addCollectable();
}

void GameManager::renderGame() {
	for (Obstacle* obstacle : obstacles) {
		obstacle->render();
	}
	for (Collectable* collectable : collectables) {
		collectable->render();
	}
	player->render();
	lowerSection->render();
	upperSection->render();
}

void GameManager::handleKeyboardDown(unsigned char keyboardInput) {
	switch (keyboardInput) {
	case 'w':
		player->jump();
		break;
	case 's':
		player->duck();
		break;
	}
}

void GameManager::handleKeyboardUp(unsigned char keyboardInput) {
	switch (keyboardInput) {
	case 's':
		player->unDuck();
		break;
	}
}

void GameManager::onTimer() {
	//gameSpeed += 0.0001;
	player->applyGravity();
	collesionManager->handleCollesions();
	flowManager->moveObstacles();
	flowManager->moveCollectables();
}
