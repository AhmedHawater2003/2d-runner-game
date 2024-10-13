#pragma once
#include "BoundingBox.h"
#include <utility>

class Player : public BoundingBox
{

	private:
		double gameLowerBound;
	public:
		static const int ORIGINAL_PLAYER_WIDTH = 50;
		static const int ORIGINAL_PLAYER_HEIGHT = 50;
		Player(std::pair<double,double> position, double gameLowerBound);
		void render();
		void jump();
		void duck();
		void unDuck();
		bool isDucking();
		void applyGravity();


};


