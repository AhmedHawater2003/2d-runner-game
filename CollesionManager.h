#pragma once
#include <vector>
#include "Obstacle.h"
#include "Player.h"
#include "GameState.h"
#include "Collectable.h"
#include "Shield.h"
#include "Shrink.h"
#include "SoundPlayer.h"

class CollesionManager
	
{
	private:
		Player* player;
		GameState* gameState;
		SoundPlayer* soundPlayer;
		std::vector<Obstacle*>* obstacles;
		std::vector<Collectable*>* collectables;
		std::vector<Shield*>* shields;
		std::vector<Shrink*>* shrinks;
	public :
		CollesionManager(Player* player, GameState* gameState, std::vector<Obstacle*>* obstacles,
			std::vector<Collectable*>* collectables, std::vector<Shield*>* shields,
			std::vector<Shrink*>* shrinks, SoundPlayer* soundPlayer);
		void handleCollesions();
		void handleObstacleCollesion(Obstacle* obstacle);
		void handleCollectableCollesion(Collectable* collectable);
		void handleShieldCollesion(Shield* shield);
		void handleShrinkCollesion(Shrink* shrink);
};

