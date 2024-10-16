#define all(x) x.begin(), x.end()
#include "FlowManager.h"
#include "glut.h"


// Constant for minimum distance between obstacles
const double MIN_OBSTACLE_DISTANCE = 500.0; // Adjust this value as needed

FlowManager::FlowManager(GameState* gameState, std::vector<Obstacle*>* obstacles, std::vector<Collectable*>* collectables,
	std::vector<Shrink*>* shrinks,
	std::vector<Shield*>* shields)
	: gameState(gameState), obstacles(obstacles), collectables(collectables), shields(shields), shrinks(shrinks) {
	selectPowerUpsTimes();

}

void FlowManager::selectPowerUpsTimes() {
	for (int i = 0; i < 2; i++) {
		int oddTime = ((rand() % 10) + 1) *2 + 1;
		shieldsTimes.push_back(oddTime);
	}
	for (int i = 0; i < 2; i++) {
		int evenTime = ((rand() % 10) + 1) * 2;
		shrinksTimes.push_back(evenTime);
	}
}

void FlowManager::addCollectable() {
	bool isFloatingCollectable = std::rand() % 2;

	double collectableY = isFloatingCollectable ?
		gameState->getLowerBound() + 100 : // Floating collectable for jumping to
		gameState->getLowerBound() + 10;        // Ground-level collectable

	Collectable* collectable = new Collectable({ gameState->getWidth(), collectableY });
	if (isSomethingColliding(collectable)) {
		delete collectable;
		return;
	}
	collectables->push_back(collectable);
}

bool FlowManager::isSomethingColliding(BoundingBox* box) {
	for (auto obstacle : *obstacles) {
		if (box->isColliding(obstacle)) {
			return true;
		}
	}
	//for (auto collectable : *collectables) {
	//	if (box->isColliding(collectable)) {
	//		return true;
	//	}
	//}
	//for (auto shield : *shields) {
	//	if (box->isColliding(shield)) {
	//		return true;
	//	}
	//}
	//for (auto shrink : *shrinks) {
	//	if (box->isColliding(shrink)) {
	//		return true;
	//	}
	//}

	return false;
}

void FlowManager::addObstacle() {
	bool isElevatedObstacle = std::rand() % 2;
	double obstacleY = isElevatedObstacle ?
		gameState->getLowerBound() + 50 : // Elevated obstacle for ducking under
		gameState->getLowerBound() + 10;       // Ground-level obstacle for jumping over

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

void FlowManager::moveShields() {
	for (auto shield : *shields) { 
		auto position = shield->getPosition();
		position.first -= gameState->getSpeed();
		shield->setPosition(position);
		if (shield->getEndX() < 0) {
			shields->erase(std::remove(shields->begin(), shields->end(), shield), shields->end());
			delete shield;
		}
	}
}

void FlowManager::moveShrinks() {
	for (auto shrink : *shrinks) {
		auto position = shrink->getPosition();
		position.first -= gameState->getSpeed();
		shrink->setPosition(position);
		if (shrink->getEndX() < 0) {
			shrinks->erase(std::remove(shrinks->begin(), shrinks->end(), shrink), shrinks->end());
			delete shrink;
		}
	}
}


void FlowManager::showPowerUps() {
	int second = glutGet(GLUT_ELAPSED_TIME) / 1000;
	if (std::count(all(shieldsTimes), second)) {
		shieldsTimes.erase(std::remove(shieldsTimes.begin(), shieldsTimes.end(), second), shieldsTimes.end());
		shields->push_back(new Shield({ gameState->getWidth(), 250}));
	}
	if (std::count(all(shrinksTimes), second)) {
		shrinksTimes.erase(std::remove(shrinksTimes.begin(), shrinksTimes.end(), second), shrinksTimes.end());
		shrinks->push_back(new Shrink({ gameState->getWidth(), 300 }));
	}
}
