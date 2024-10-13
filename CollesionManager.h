#pragma once
#include <vector>
#include "Obstacle.h"
#include "Player.h"
#include "GameState.h"
#include "Collectable.h"

class CollesionManager
	
{
	private:
		Player* player;
		GameState* gameState;
		std::vector<Obstacle*>* obstacles;
		std::vector<Collectable*>* collectables;
	public :
		CollesionManager(Player* player, GameState* gameState, std::vector<Obstacle*>* obstacles, std::vector<Collectable*>* collectables);
		void handleCollesions();
		void handleObstacleCollesion(Obstacle* obstacle);
		void handleCollectableCollesion(Collectable* collectable);


};

