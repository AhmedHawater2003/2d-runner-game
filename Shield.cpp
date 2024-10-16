#include "Shield.h"
#include <glut.h>

Shield::Shield(std::pair<double, double> position)
    : BoundingBox(position, POWERUP_WIDTH, POWERUP_HEIGHT) {
}

std::pair<double, double> Shield::getPosition() {
    return position;
}

void Shield::setPosition(std::pair<double, double> position) {
    this->position = position;
}

void Shield::render() { 
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2d(position.first, position.second);
    glVertex2d(position.first + POWERUP_WIDTH, position.second);
    glVertex2d(position.first + POWERUP_WIDTH, position.second + POWERUP_HEIGHT);
    glVertex2d(position.first, position.second + POWERUP_HEIGHT);
    glEnd();
}