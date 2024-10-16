#pragma once
#include "BoundingBox.h"
#include <utility>
class Shrink: public BoundingBox
{
public:
	static const int POWERUP_WIDTH = 30;
	static const int POWERUP_HEIGHT = 30;
	Shrink(std::pair<double, double> position);
	std::pair<double, double> getPosition();
	void setPosition(std::pair<double, double> position);
	void render();
};
