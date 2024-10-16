#pragma once
#include "BoundingBox.h"
#include <utility>
class Obstacle: public BoundingBox
{
private:

public:
	double rotationAngel = 0;

	static const int OBSTACLE_WIDTH = 30;
	static const int OBSTACLE_HEIGHT = 30;
	Obstacle(std::pair<double, double> position);
	std::pair<double, double> getPosition();
	void setPosition(std::pair<double, double> position);
	void render();

};

