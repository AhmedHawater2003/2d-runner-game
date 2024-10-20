#include "Lives.h"
#include <cmath>
#include <glut.h>

Lives::Lives(double x, double y, GameState* gameState) : x(x), y(y), gameState(gameState) {
}

void Lives::render() {
    int livesLeft = gameState->getLives();
    double heartSize = 30.0; // Size of each heart
    double spacing = 10.0;   // Space between hearts

    for (int i = 0; i < livesLeft; ++i) {
        renderUFO(x + i * (heartSize + spacing), y, heartSize);
    }
}

void Lives::renderUFO(double x, double y, double size) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(size, size, 1.0);

    // Draw the saucer
    glColor3f(158 / 255.0, 166 / 255.0, 180 / 255.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 0.5 * cos(angle);
        float y = 0.25 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw bottom lights using larger triangles
    glColor3f(255 / 255.0, 255 / 255.0, 255 / 255.0);  // Bright white
    for (int i = 0; i < 8; i++) {
        float angle = i * (3.14159 / 4);
        glBegin(GL_TRIANGLES);
        // Made triangles larger and more visible
        glVertex2f(0.48 * cos(angle), 0.24 * sin(angle));
        glVertex2f(0.48 * cos(angle + 0.3), 0.24 * sin(angle + 0.3));
        glVertex2f(0.4 * cos(angle + 0.15), 0.18 * sin(angle + 0.15));
        glEnd();
    }

    // Draw the dome using polygon
    glColor3f(101 / 255.0, 220 / 255.0, 252 / 255.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++) {
        float angle = i * 3.14159 / 180;
        float x = 0.25 * cos(angle);
        float y = 0.25 * sin(angle) + 0.25;
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();
}