#pragma once
#include "Time.h"
#include "Score.h"
#include "GameState.h"
#include "Lives.h"
class GameUpperSection
{
	private:
		double height;
		GameState* gameState;
		Time* gameTime;
		Score* gameScore;
		Lives* playerLives;
	public:
		GameUpperSection(GameState* gameState, double height);
		void render();
};

