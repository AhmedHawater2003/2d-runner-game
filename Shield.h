#pragma once
#include "BoundingBox.h"
#include <utility>
class Shield : public BoundingBox
{
public:
	static const int POWERUP_WIDTH = 30;
	static const int POWERUP_HEIGHT = 30;
	double animationTime = 0.0;
	Shield(std::pair<double, double> position);
	std::pair<double, double> getPosition();
	void setPosition(std::pair<double, double> position);
	void render();
};
