#include "Collectable.h"
#include <glut.h>

Collectable::Collectable(std::pair<double, double> position)
    : BoundingBox(position, COLLECTABLE_WIDTH, COLLECTABLE_HEIGHT) {
}

std::pair<double, double> Collectable::getPosition() {
    return position;
}

void Collectable::setPosition(std::pair<double, double> position) {
    this->position = position;
}

void Collectable::render() {
    double centerX = position.first + COLLECTABLE_WIDTH / 2;
    double baseY = position.second;

    glPushMatrix();
    // Rotate the rocket around its center 45 degrees
    
    glTranslated(position.first, position.second, 0);
    glRotated(45, 0, 0, 1);
    glTranslated(-position.first, -position.second, 0);
    // Draw rocket body (rectangle)
    glColor3f(0.0, 0.0, 1.0);  // Blue color for the body
    glBegin(GL_QUADS);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY);  // Bottom left
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY);  // Bottom right
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);  // Top right
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);  // Top left
    glEnd();

    // Draw rocket nose cone (triangle)
    glColor3f(1.0, 0.0, 0.0);  // Red color for the nose cone
    glBegin(GL_TRIANGLES);
    glVertex2d(centerX, baseY + COLLECTABLE_HEIGHT);  // Tip of the nose
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);  // Bottom left of the nose cone
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);  // Bottom right of the nose cone
    glEnd();

    // Draw rocket fins (two small rectangles on the sides)
    glColor3f(0.8, 0.8, 0.8);  // Light gray for the fins
    glBegin(GL_QUADS);
    // Left fin
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY);  // Bottom left
    glVertex2d(centerX - COLLECTABLE_WIDTH / 2, baseY);  // Bottom right of the left fin
    glVertex2d(centerX - COLLECTABLE_WIDTH / 2, baseY + COLLECTABLE_HEIGHT * 0.3);  // Top right of the left fin
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.3);  // Top left
    glEnd();

    glBegin(GL_QUADS);
    // Right fin
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY);  // Bottom left
    glVertex2d(centerX + COLLECTABLE_WIDTH / 2, baseY);  // Bottom right of the right fin
    glVertex2d(centerX + COLLECTABLE_WIDTH / 2, baseY + COLLECTABLE_HEIGHT * 0.3);  // Top right of the right fin
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.3);  // Top left
    glEnd();

    // Draw rocket flames using simple lines
    glColor3f(1.0, 0.5, 0.0);  // Orange color for the flame

    glBegin(GL_LINES);
    glVertex2d(centerX, baseY);                            // Flame base (tip)
    glVertex2d(centerX - COLLECTABLE_WIDTH / 8, baseY - COLLECTABLE_HEIGHT * 0.2);  // Left flame
    glVertex2d(centerX, baseY);                            // Flame base (tip)
    glVertex2d(centerX + COLLECTABLE_WIDTH / 8, baseY - COLLECTABLE_HEIGHT * 0.2);  // Right flame
    glEnd();

    glPopMatrix();
}
