#include "Obstacle.h"
#include <glut.h>

Obstacle::Obstacle(std::pair<double, double> position)
	:BoundingBox(position, OBSTACLE_WIDTH, OBSTACLE_HEIGHT){
}

std::pair<double, double> Obstacle::getPosition() {
	return position;
}

void Obstacle::setPosition(std::pair<double, double> position) {
	this->position = position;
}

void Obstacle::render() {
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(position.first, position.second);
	glVertex2d(position.first + OBSTACLE_WIDTH, position.second);
	glVertex2d(position.first + OBSTACLE_WIDTH, position.second + OBSTACLE_HEIGHT);
	glVertex2d(position.first, position.second + OBSTACLE_HEIGHT);
	glEnd();

}