#pragma once
#include <vector>
#include "GameLowerSection.h"
#include "GameUpperSection.h"
#include "FlowManager.h"
#include "Obstacle.h"
#include "Collectable.h"
#include "Player.h"
#include "CollesionManager.h"
#include "GameState.h"

class GameManager
{
private:
   
    GameState* gameState;
    GameLowerSection* lowerSection;
    GameUpperSection* upperSection;
    FlowManager* flowManager;
    Player* player;
    CollesionManager* collesionManager;
    std::vector<Obstacle*> obstacles;
    std::vector<Collectable*> collectables;

public:
    GameManager(double gameHeight, double gameWidth);
    void onTimer();
    void renderGame();
    void handleKeyboardDown(unsigned char keyboardInput);
    void handleKeyboardUp(unsigned char keyboardInput);
};
