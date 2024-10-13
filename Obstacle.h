#pragma once
#include "BoundingBox.h"
#include <utility>
class Obstacle: public BoundingBox
{

public:
	static const int OBSTACLE_WIDTH = 20;
	static const int OBSTACLE_HEIGHT = 20;
	Obstacle(std::pair<double, double> position);
	std::pair<double, double> getPosition();
	void setPosition(std::pair<double, double> position);
	void render();

};

