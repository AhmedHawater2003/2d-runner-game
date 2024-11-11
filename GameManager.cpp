#include <Windows.h>
#include "GameManager.h"
#include "Text.h"
#include <glut.h>
#include <string>

GameManager::GameManager(double gameHeight, double gameWidth) {
	gameState = new GameState(0, 5, gameWidth, gameHeight, 100, gameHeight - 100, 3, 90);
	lowerSection = new GameLowerSection(gameState, gameState->getLowerBound());
	upperSection = new GameUpperSection(gameState, gameHeight - gameState->getUpperBound());
	player = new Player({ 10, gameState->getLowerBound() }, gameState);
	flowManager = new FlowManager(gameState, &obstacles, &collectables, &shrinks, &shields);
	soundPlayer = new SoundPlayer();
	collesionManager = new CollesionManager(player, gameState, &obstacles, &collectables, &shields, &shrinks, soundPlayer);
	initializeStars();
}

void GameManager::initializeStars() {
	stars.clear();
	for (int i = 0; i < 200; ++i) {
		double x = rand() % static_cast<int>(gameState->getWidth());
		double y = gameState->getHeight() - 150 - (rand() % 200); // Between gameHeight - 100 and gameHeight - 300
		double size = 10 + (rand() % 6); // Random size between 10 and 10
		stars.push_back(new Star(x, y, size));
	}
}

void GameManager::renderGame() {
	if (gameState->isGameWon) {
		std::string message = "Game Over, you did it! Your score: " + std::to_string(gameState->getScore());
		Text(gameState->getWidth() / 2 - 150, gameState->getHeight() / 2, message, 0, 1, 0).render();
		return;
	}
	if (gameState->isGameLost) {
		std::string message = "Game Lost, what a shame! Your score: " + std::to_string(gameState->getScore());
		Text(gameState->getWidth() / 2 - 150, gameState->getHeight() / 2, message, 1, 0, 0).render();
		return;
	}

	player->render();
	lowerSection->render();
	upperSection->render();

	glPushMatrix();
	for (Obstacle* obstacle : obstacles) {
		auto currentPosition = obstacle->getPosition();
		obstacle->setPosition({ currentPosition.first + player->obstacleBackOffDistance , currentPosition.second });
		obstacle->render();
	}
	for (Collectable* collectable : collectables) {
		auto currentPosition = collectable->getPosition();
		collectable->setPosition({ currentPosition.first + player->obstacleBackOffDistance , currentPosition.second });
		collectable->render();
	}
	for (Shield* shield : shields) {
		auto currentPosition = shield->getPosition();
		shield->setPosition({ currentPosition.first + player->obstacleBackOffDistance , currentPosition.second });
		shield->render();
	}
	for (Shrink* shrink : shrinks) {
		auto currentPosition = shrink->getPosition();
		shrink->setPosition({ currentPosition.first + player->obstacleBackOffDistance , currentPosition.second });
		shrink->render();
	}
	glPopMatrix();

	if(player->getShrinkingTime())
		Text(50, gameState->getHeight() - 100, "Shrink: " + std::to_string(player->getShrinkingTime())).render();
	if(player->getShieldingTime())
		Text(150, gameState->getHeight() - 100, "Shield: " + std::to_string(player->getShieldingTime())).render();

	for (Star* star : stars) {
		star->render();
	}

	player->obstacleBackOffDistance /= 4;
}

void GameManager::updateStars() {
	for (Star* star : stars) {
		star->update();
	}
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
	if (!gameState->isGameLost && !gameState->isGameWon) {
		soundPlayer->playBackground();

		

		player->applyGravity();
		collesionManager->handleCollesions();
		flowManager->showPowerUps();
		flowManager->moveObstacles();
		flowManager->moveCollectables();
		flowManager->moveShields();
		flowManager->moveShrinks();

		int currentSecond = glutGet(GLUT_ELAPSED_TIME) / 1000;
		if (currentSecond > gameState->getLastCapturedSecond()) {
			gameState->setLastCapturedSecond(currentSecond);
			player->decreasePowerUpTime();
			gameState->setSpeed(gameState->getSpeed() + 0.05);
			gameState->gravity -= 5;
		}

		updateStars();

		if (!gameState->getLives()) {
			gameState->isGameLost = true;
		}
		if (gameState->getLastCapturedSecond() > gameState->gameDuration) {
			gameState->isGameWon = true;
		}
	}
	else {
		if (!gameState->isGameOver) {
			if (gameState->isGameWon) {
				soundPlayer->playGameWon();
			}
			if (gameState->isGameLost) {
				soundPlayer->playGameLost();
			}
			gameState->isGameOver = true;
		}
	}

}
