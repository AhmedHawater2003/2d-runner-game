#include "GameLowerSection.h"
#include <cmath>
#include <glut.h>

GameLowerSection::GameLowerSection(GameState* gameState, double height): gameState(gameState), height(height) {
}

void GameLowerSection::render() {
    glPushMatrix();

    // Draw the base of the moon surface (a rectangle)
    glColor3f(0.3f, 0.3f, 0.35f); // Dark grayish color for the moon surface
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(gameState->getWidth(), 0);
    glVertex2d(gameState->getWidth(), height);
    glVertex2d(0, height);
    glEnd();

    // Draw some craters (using GL_TRIANGLE_FAN to form circles)
    glColor3f(0.15f, 0.15f, 0.2f);
    for (int i = 0; i < 3; ++i) { // Draw 3 craters
        double craterX = (gameState->getWidth() / 4) * (i + 1); // Place them evenly
        double craterY = height / 2;  // Craters in the middle of the ground
        double craterRadius = 20.0 + 10 * i; // Varying sizes of craters

        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(craterX, craterY); // Center of the crater
        for (int j = 0; j <= 20; ++j) {
            double angle = 2.0 * 3.14 * j / 20;
            double dx = cos(angle) * craterRadius;
            double dy = sin(angle) * craterRadius;
            glVertex2d(craterX + dx, craterY + dy);
        }
        glEnd();
    }

    // Draw some triangular rocks on the surface (GL_TRIANGLES)
    glColor3f(0.2f, 0.2f, 0.25f);
    glBegin(GL_TRIANGLES);
    glVertex2d(100, height); // Rock 1
    glVertex2d(120, height);
    glVertex2d(110, height + -25);

    glVertex2d(300, height); // Rock 2
    glVertex2d(330, height);
    glVertex2d(315, height -25);
    glEnd();

    // Draw small ellipses for bumpy surface texture (GL_POLYGON)
    glColor3f(0.2f, 0.2f, 0.25f);
    for (int i = 0; i < 5; ++i) {
        double bumpX = (gameState->getWidth() / 6) * (i + 1);
        double bumpY = height / 4;
        double bumpWidth = 10.0;
        double bumpHeight = 5.0;

        glBegin(GL_POLYGON);
        for (int j = 0; j <= 20; ++j) {
            double angle = 2.0 * 3.14 * j / 20;
            double dx = cos(angle) * bumpWidth;
            double dy = sin(angle) * bumpHeight;
            glVertex2d(bumpX + dx, bumpY + dy);
        }
        glEnd();
    }

    glPopMatrix();
}

