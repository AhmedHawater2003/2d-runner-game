#pragma once
#include <vector>
#include "Obstacle.h"
#include "Collectable.h"
#include "Shrink.h"
#include "Shield.h"
#include "GameState.h"

class FlowManager
{
private:
	std::vector<Obstacle*>* obstacles;
	std::vector<Collectable*>* collectables;
	std::vector<Shrink*>* shrinks;
	std::vector<Shield*>* shields;

	std::vector<int> shrinksTimes;
	std::vector<int> shieldsTimes;
	GameState* gameState;
public:
	FlowManager(GameState* gameState, std::vector<Obstacle*>* obstacles, std::vector<Collectable*>* collectables,
		std::vector<Shrink*>* shrinks,
		std::vector<Shield*>* shields);
	void addObstacle();
	void addCollectable();
	void showPowerUps();
	void moveShields();
	void moveShrinks();
	void moveObstacles();
	void moveCollectables();
	void selectPowerUpsTimes();
	bool isSomethingColliding(BoundingBox* box);
};

