#include "Collectable.h"
#include <glut.h>

Collectable::Collectable(std::pair<double, double> position)
	:BoundingBox(position, COLLECTABLE_WIDTH, COLLECTABLE_HEIGHT) {
}

std::pair<double, double> Collectable::getPosition() {
	return position;
}

void Collectable::setPosition(std::pair<double, double> position) {
	this->position = position;
}

void Collectable::render() {

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(position.first, position.second);
	glVertex2d(position.first + COLLECTABLE_WIDTH, position.second);
	glVertex2d(position.first + COLLECTABLE_WIDTH, position.second + COLLECTABLE_HEIGHT);
	glVertex2d(position.first, position.second + COLLECTABLE_HEIGHT);
	glEnd();

}