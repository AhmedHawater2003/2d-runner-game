#include "FlowManager.h"


// Constant for minimum distance between obstacles
const double MIN_OBSTACLE_DISTANCE = 500.0; // Adjust this value as needed

FlowManager::FlowManager(GameState* gameState, std::vector<Obstacle*>* obstacles, std::vector<Collectable*>* collectables)
    : gameState(gameState), obstacles(obstacles), collectables(collectables) {}

void FlowManager::addCollectable() {
    bool isFloatingCollectable = std::rand() % 2;

    double collectableY = isFloatingCollectable ?
        gameState->getLowerBound() + 100 : // Floating collectable for jumping to
        gameState->getLowerBound();        // Ground-level collectable

    Collectable* collectable = new Collectable({ gameState->getWidth(), collectableY });
    if (isCollectableCollidingWithObstacle(collectable)) {
		delete collectable;
		return;
	}
    collectables->push_back(collectable);
}

bool FlowManager::isCollectableCollidingWithObstacle(Collectable* collectable) {
    for (auto obstacle : *obstacles) {
        if (collectable->isColliding(obstacle)) {
			return true;
		}
	}
	return false;
}

void FlowManager::addObstacle() {
    bool isElevatedObstacle = std::rand() % 2;
    double obstacleY = isElevatedObstacle ?
        gameState->getLowerBound() + 50 : // Elevated obstacle for ducking under
        gameState->getLowerBound();       // Ground-level obstacle for jumping over

    double obstacleX = gameState->getWidth();
    if (!obstacles->empty()) {
        obstacleX = std::max(obstacleX, obstacles->back()->getPosition().first + MIN_OBSTACLE_DISTANCE);
    }

    obstacles->push_back(new Obstacle({ obstacleX, obstacleY }));
}

void FlowManager::moveObstacles() {
    for (auto obstacle : *obstacles) {
        auto position = obstacle->getPosition();
        position.first -= gameState->getSpeed();
        obstacle->setPosition(position);
        if (obstacle->getEndX() < 0) {
            obstacles->erase(std::remove(obstacles->begin(), obstacles->end(), obstacle), obstacles->end());
            delete obstacle;
        }
    }

    // Spawn new obstacles if needed
    if (obstacles->empty() || obstacles->back()->getPosition().first < gameState->getWidth() - 200) {
        addObstacle();
    }
}

void FlowManager::moveCollectables() {
    for (auto collectable : *collectables) {
        auto position = collectable->getPosition();
        position.first -= gameState->getSpeed();
        collectable->setPosition(position);
        if (collectable->getEndX() < 0) {
            collectables->erase(std::remove(collectables->begin(), collectables->end(), collectable), collectables->end());
            delete collectable;
        }
    }

    // Spawn new collectables if needed
    if (collectables->empty() || collectables->back()->getPosition().first < gameState->getWidth() - 300) {
        addCollectable();
    }
}
