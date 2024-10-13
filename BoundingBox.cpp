#include "BoundingBox.h"
#include <utility>

BoundingBox::BoundingBox(std::pair<double, double> position, double width, double height)
	: position(position), width(width), height(height)
{
}

double BoundingBox::getEndX()
{
	return position.first + width;
}

double BoundingBox::getStartX()
{
	return position.first;
}

double BoundingBox::getEndY()
{
	return position.second + height;
}

double BoundingBox::getStartY()
{
	return position.second;
}

bool BoundingBox::isColliding(BoundingBox* other)
{
	if (getEndX() < other->getStartX() || getStartX() > other->getEndX())
	{
		return false;
	}
	if (getEndY() < other->getStartY() || getStartY() > other->getEndY())
	{
		return false;
	}
	return true;
}
