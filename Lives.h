#pragma once
#include "GameState.h"
class Lives
{
private:
    double x;
    double y;
    GameState* gameState;
public:
    Lives(double x, double y, GameState* gameState);
    void render();
};
