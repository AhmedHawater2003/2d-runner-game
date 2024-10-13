#pragma once
#include "GameState.h"
class Score
{
    private:
        double x;
        double y;
        GameState* gameState;
    public:
        Score(double x, double y, GameState* gameState);
        void render();
};
