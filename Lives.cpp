#include "Lives.h"
#include <cmath>
#include <glut.h>

Lives::Lives(double x, double y, GameState* gameState) : x(x), y(y), gameState(gameState) {
}

void Lives::render() {
    int livesLeft = gameState->getLives();
    double heartSize = 20.0; // Size of each heart
    double spacing = 10.0;   // Space between hearts

    for (int i = 0; i < livesLeft; ++i) {
        renderUFO(x + i * (heartSize + spacing), y, heartSize);
    }
}

void Lives::renderUFO(double x, double y, double size) {

    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(size, size, 1.0);

    glColor3f(158 / 255.0, 166 / 255.0, 180 / 255.0);
    // Draw the saucer
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 0.5 * cos(angle);
        float y = 0.25 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the dome
    glColor3f(101/255.0, 220/255.0, 252/255.0);
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
