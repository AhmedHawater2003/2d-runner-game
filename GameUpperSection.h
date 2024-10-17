#pragma once
#include "GameTime.h"
#include "Score.h"
#include "GameState.h"
#include "Lives.h"
class GameUpperSection
{
	private:
		double height;
		GameState* gameState;
		GameTime* gameTime;
		Score* gameScore;
		Lives* playerLives;
	public:
		GameUpperSection(GameState* gameState, double height);
		void render();
};

