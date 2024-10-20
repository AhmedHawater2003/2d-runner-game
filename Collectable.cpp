#include "Collectable.h"
#include <cmath>
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

    double amplitude = 5.0; // Adjust this value for bigger/smaller motion
    double frequency = 2.0; // Adjust this for faster/slower motion
    double verticalOffset = amplitude * sin(frequency * colorChangeFactor);

    double centerX = position.first + COLLECTABLE_WIDTH / 2;
    double baseY = position.second + verticalOffset; // Add vertical offset here

    colorChangeFactor += 0.05; // Keep this as a time counter

    // Use sine or cosine functions to oscillate between 0 and 1 for RGB
    float redFinColor = (sin(colorChangeFactor) + 1) / 2;
    float greenFinColor = (sin(colorChangeFactor + 2) + 1) / 2;  // Offset for variation
    float blueFinColor = (sin(colorChangeFactor + 4) + 1) / 2;   // Offset for variation

    glPushMatrix();
    glTranslated(position.first, baseY, 0); // Use baseY here
    glRotated(45, 0, 0, 1);
    glTranslated(-position.first, -baseY, 0); // And here

    // Rocket body (no changes here)
    glColor3f(0.5, 0.5, 0.5);  // Blue body
    glBegin(GL_QUADS);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY);
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY);
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);
    glEnd();

    // Rocket nose (no changes here)
    glColor3f(1.0, 0.0, 0.0);  // Red nose
    glBegin(GL_TRIANGLES);
    glVertex2d(centerX, baseY + COLLECTABLE_HEIGHT);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.6);
    glEnd();

    // Rocket fins with dynamic colors
    glColor3f(redFinColor, greenFinColor, blueFinColor);
    glBegin(GL_QUADS);
    // Left fin
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 2, baseY);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 2, baseY + COLLECTABLE_HEIGHT * 0.3);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.3);
    glEnd();

    glBegin(GL_QUADS);
    // Right fin
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY);
    glVertex2d(centerX + COLLECTABLE_WIDTH / 2, baseY);
    glVertex2d(centerX + COLLECTABLE_WIDTH / 2, baseY + COLLECTABLE_HEIGHT * 0.3);
    glVertex2d(centerX + COLLECTABLE_WIDTH / 4, baseY + COLLECTABLE_HEIGHT * 0.3);
    glEnd();

    // Rocket flames (no changes here)
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_LINES);
    glVertex2d(centerX, baseY);
    glVertex2d(centerX - COLLECTABLE_WIDTH / 8, baseY - COLLECTABLE_HEIGHT * 0.2);
    glVertex2d(centerX, baseY);
    glVertex2d(centerX + COLLECTABLE_WIDTH / 8, baseY - COLLECTABLE_HEIGHT * 0.2);
    glEnd();

    glPopMatrix();

}
