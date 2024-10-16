#pragma once
#include "BoundingBox.h"
#include "GameState.h"
#include <utility>

class Player : public BoundingBox
{

	private:
		GameState* gameState;
		int shieldingTime, shrinkingTime;

	public:
		static const int ORIGINAL_PLAYER_WIDTH = 50;
		static const int ORIGINAL_PLAYER_HEIGHT = 50;
		Player(std::pair<double,double> position, GameState* gameState);
		void render();
		void jump();
		void duck();
		void unDuck();
		bool isDucking();
		void applyGravity();
		void decreasePowerUpTime();
		int getShrinkingTime();
		int getShieldingTime();
		void setShrinkingTime(int time);
		void setShieldingTime(int time);




};


