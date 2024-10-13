#pragma once
#include <utility>
class BoundingBox
{
	protected:
		std::pair<double, double> position;
		double width, height;
	public:
		virtual ~BoundingBox() = default;
		double getStartX();
		double getEndX();
		double getStartY();
		double getEndY();
		bool isColliding(BoundingBox* other);
		BoundingBox(std::pair<double, double> position, double width, double height);


};

