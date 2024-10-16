#include "Shrink.h"
#include <glut.h>

Shrink::Shrink(std::pair<double, double> position)
    : BoundingBox(position, POWERUP_WIDTH, POWERUP_HEIGHT) {
}

std::pair<double, double> Shrink::getPosition() {
    return position;
}

void Shrink::setPosition(std::pair<double, double> position) {
    this->position = position;
}

void Shrink::render() {
    // render a simple orange rectangle
    glColor3f(1.0f, 0.5f, 0.0f);  // Orange
    glBegin(GL_QUADS);
    glVertex2d(position.first, position.second);
    glVertex2d(position.first + POWERUP_WIDTH, position.second);
    glVertex2d(position.first + POWERUP_WIDTH, position.second + POWERUP_HEIGHT);
    glVertex2d(position.first, position.second + POWERUP_HEIGHT);
    glEnd();
}