#pragma once
#include "GameState.h"
class GameLowerSection
{
	private:
		GameState* gameState;
		double height;
	public:
		GameLowerSection(GameState* gameState, double height);
		void render();
};

