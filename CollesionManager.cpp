#include "CollesionManager.h"


CollesionManager::CollesionManager(Player* player, GameState* gameState, std::vector<Obstacle*>* obstacles,
	std::vector<Collectable*>* collectables, std::vector<Shield*>* shields, std::vector<Shrink*>* shrinks)
{
	this->player = player;
	this->gameState = gameState;
	this->obstacles = obstacles;
	this->collectables = collectables;
	this->shields = shields;
	this->shrinks = shrinks;
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

	for (Shield* shield : *shields)
	{
		if (player->isColliding(shield))
		{
			handleShieldCollesion(shield);
			return;
		}
	}

	for (Shrink* shrink : *shrinks)
	{
		if (player->isColliding(shrink))
		{
			handleShrinkCollesion(shrink);
			return;
		}
	}
}

void CollesionManager::handleObstacleCollesion(Obstacle* obstacle)
{
	obstacles->erase(std::remove(obstacles->begin(), obstacles->end(), obstacle), obstacles->end());
	delete obstacle;
	if(player->getShieldingTime() == 0)
		gameState->setLives(gameState->getLives() - 1);
}

void CollesionManager::handleCollectableCollesion(Collectable* collectable)
{
	collectables->erase(std::remove(collectables->begin(), collectables->end(), collectable), collectables->end());
	delete collectable;
	gameState->setScore(gameState->getScore() + 1);
}

void CollesionManager::handleShieldCollesion(Shield* shield)
{
	shields->erase(std::remove(shields->begin(), shields->end(), shield), shields->end());
	delete shield;
	player->setShieldingTime(10);

}

void CollesionManager::handleShrinkCollesion(Shrink* shrink)
{
	shrinks->erase(std::remove(shrinks->begin(), shrinks->end(), shrink), shrinks->end());
	delete shrink;
	player->setShrinkingTime(10);

}