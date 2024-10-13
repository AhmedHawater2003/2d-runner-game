#pragma once
#include "BoundingBox.h"
#include <utility>
class Collectable : public BoundingBox
{

public:
	static const int COLLECTABLE_WIDTH = 30;
	static const int COLLECTABLE_HEIGHT = 30;
	Collectable(std::pair<double, double> position);
	std::pair<double, double> getPosition();
	void setPosition(std::pair<double, double> position);
	void render();

};

