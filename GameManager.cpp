#include "GameManager.h"
#include "Text.h"
#include <glut.h>
#include <string>

GameManager::GameManager(double gameHeight, double gameWidth){
	gameState = new GameState(0, 3, gameWidth, gameHeight, 100, gameHeight - 100, 3, 120);
	lowerSection = new GameLowerSection(gameState, gameState->getLowerBound());
	upperSection = new GameUpperSection(gameState, gameHeight - gameState->getUpperBound());
	player = new Player({ 10, gameState->getLowerBound() }, gameState);
	flowManager = new FlowManager(gameState, &obstacles, &collectables, &shrinks, &shields);
	collesionManager = new CollesionManager(player, gameState ,&obstacles, &collectables, &shields, &shrinks);
}

void GameManager::renderGame() {
	if (gameState->isGameOver) {
		std::string message = "Game Over, you won! Your score: " + std::to_string(gameState->getScore());
		Text(gameState->getWidth() / 2 - 150, gameState->getHeight() / 2, message, 0, 1, 0).render();
		return;
	}
	if (gameState->isGameLost) {
		std::string message = "Game Lost, what a shame! Your score: " + std::to_string(gameState->getScore());
		Text(gameState->getWidth() / 2 - 150, gameState->getHeight() / 2, message, 1, 0, 0).render();
		return;
	}

	for (Obstacle* obstacle : obstacles) {
		obstacle->render();
	}
	for (Collectable* collectable : collectables) {
		collectable->render();
	}
	for (Shield* shield : shields) {
		shield->render();
	}
	for (Shrink* shrink : shrinks) {
		shrink->render();
	}
	player->render();
	lowerSection->render();
	upperSection->render();
	flowManager->showPowerUps();
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
	if (!gameState->isGameLost && !gameState->isGameOver) {
		player->applyGravity();

		collesionManager->handleCollesions();
		flowManager->moveObstacles();
		flowManager->moveCollectables();
		flowManager->moveShields();
		flowManager->moveShrinks();

		int currentSecond = glutGet(GLUT_ELAPSED_TIME) / 1000;
		if (currentSecond > gameState->getLastCapturedSecond()) {
			gameState->setLastCapturedSecond(currentSecond);
			player->decreasePowerUpTime();
			//gameState->setSpeed(gameState->getSpeed() + 0.1);
		}

		//if (!gameState->getLives()) {
		//	gameState->isGameLost = true;
		//}
		//if (gameState->getLastCapturedSecond() > gameState->gameDuration) {
		//	gameState->isGameOver = true;
		//}
	}

}
