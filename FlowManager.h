#pragma once
#include <vector>
#include "Obstacle.h"
#include "Collectable.h"
#include "GameState.h"

class FlowManager
{
	private:
		std::vector<Obstacle*>* obstacles;
		std::vector<Collectable*>* collectables;
		GameState* gameState;
	public:
		FlowManager(GameState* gameState, std::vector<Obstacle*>* obstacles, std::vector<Collectable*>* collectables);
		void addObstacle();
		void addCollectable();
		void moveObstacles();
		void moveCollectables();
		bool isCollectableCollidingWithObstacle(Collectable* collectable);
};

