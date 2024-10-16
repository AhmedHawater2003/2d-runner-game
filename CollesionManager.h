#pragma once
#include <vector>
#include "Obstacle.h"
#include "Player.h"
#include "GameState.h"
#include "Collectable.h"
#include "Shield.h"
#include "Shrink.h"

class CollesionManager
	
{
	private:
		Player* player;
		GameState* gameState;
		std::vector<Obstacle*>* obstacles;
		std::vector<Collectable*>* collectables;
		std::vector<Shield*>* shields;
		std::vector<Shrink*>* shrinks;
	public :
		CollesionManager(Player* player, GameState* gameState, std::vector<Obstacle*>* obstacles,
			std::vector<Collectable*>* collectables, std::vector<Shield*>* shields,
			std::vector<Shrink*>* shrinks);
		void handleCollesions();
		void handleObstacleCollesion(Obstacle* obstacle);
		void handleCollectableCollesion(Collectable* collectable);
		void handleShieldCollesion(Shield* shield);
		void handleShrinkCollesion(Shrink* shrink);
};

