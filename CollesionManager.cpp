#include "CollesionManager.h"


CollesionManager::CollesionManager(Player* player, GameState* gameState, std::vector<Obstacle*>* obstacles, std::vector<Collectable*>* collectables)
{
	this->player = player;
	this->gameState = gameState;
	this->obstacles = obstacles;
	this->collectables = collectables;
}

void CollesionManager::handleCollesions()
{
	for (Obstacle* obstacle : *obstacles)
	{
		if (player->isColliding(obstacle))
		{
			handleObstacleCollesion(obstacle);
			return;
		}
	}

	for (Collectable* collectable : *collectables)
	{
		if (player->isColliding(collectable))
		{
			handleCollectableCollesion(collectable);
			return;
		}
	}
}

void CollesionManager::handleObstacleCollesion(Obstacle* obstacle)
{
	obstacles->erase(std::remove(obstacles->begin(), obstacles->end(), obstacle), obstacles->end());
	delete obstacle;
	gameState->setLives(gameState->getLives() - 1);
}

void CollesionManager::handleCollectableCollesion(Collectable* collectable)
{
	collectables->erase(std::remove(collectables->begin(), collectables->end(), collectable), collectables->end());
	delete collectable;
	gameState->setScore(gameState->getScore() + 1);
}