
#include "Shrink.h"
#include <cmath>
#include <glut.h>

Shrink::Shrink(std::pair<double, double> position)
    : BoundingBox(position, POWERUP_WIDTH, POWERUP_HEIGHT), animationTime(0.0) {
}

std::pair<double, double> Shrink::getPosition() {
    return position;
}

void Shrink::setPosition(std::pair<double, double> position) {
    this->position = position;
}

void Shrink::render() {
    // Update the animation time
    animationTime += 0.05;

    // Calculate scaling factor using a sine wave for smooth oscillation
    double scaleFactor = 1.0 + 0.2 * std::sin(animationTime);

    // Calculate center position
    double centerX = position.first + POWERUP_WIDTH / 2;
    double centerY = position.second + POWERUP_HEIGHT / 2;

    // Draw outer circle
    glColor4f(0.7f, 0.0f, 0.7f, 1.0f);  // Dark purple
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(centerX, centerY);
    for (int i = 0; i <= 100; ++i) {
        double angle = 2.0 * 3.14159 * i / 100;
        glVertex2d(centerX + cos(angle) * POWERUP_WIDTH / 2 * scaleFactor,
            centerY + sin(angle) * POWERUP_HEIGHT / 2 * scaleFactor);
    }
    glEnd();

    // Draw three nested squares, each smaller than the last
    for (int i = 0; i < 3; ++i) {
        double size = POWERUP_WIDTH * (0.8 - 0.2 * i) * scaleFactor;

        // Alternate colors between light purple and magenta
        if (i % 2 == 0) {
            glColor4f(0.8f, 0.3f, 0.8f, 1.0f);  // Light purple
        }
        else {
            glColor4f(1.0f, 0.0f, 1.0f, 1.0f);  // Magenta
        }

        glBegin(GL_QUADS);
        glVertex2d(centerX - size / 2, centerY - size / 2);
        glVertex2d(centerX + size / 2, centerY - size / 2);
        glVertex2d(centerX + size / 2, centerY + size / 2);
        glVertex2d(centerX - size / 2, centerY + size / 2);
        glEnd();
    }

    // Draw rotating triangles
    glPushMatrix();
    glTranslated(centerX, centerY, 0);
    glRotated(animationTime * 100, 0, 0, 1);  // Rotate based on animation time
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glRotated(90 * i, 0, 0, 1);
        glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 1.0f, 0.0f, 0.7f);  // Yellow, semi-transparent
        glVertex2d(0, -POWERUP_HEIGHT * 0.4 * scaleFactor);
        glVertex2d(-POWERUP_WIDTH * 0.1 * scaleFactor, -POWERUP_HEIGHT * 0.25 * scaleFactor);
        glVertex2d(POWERUP_WIDTH * 0.1 * scaleFactor, -POWERUP_HEIGHT * 0.25 * scaleFactor);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

    // Draw pulsing inner circle
    double innerRadius = POWERUP_WIDTH * 0.15 * (1.0 + 0.2 * sin(animationTime * 3)) * scaleFactor;
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);  // White, slightly transparent
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(centerX, centerY);
    for (int i = 0; i <= 100; ++i) {
        double angle = 2.0 * 3.14159 * i / 100;
        glVertex2d(centerX + cos(angle) * innerRadius, centerY + sin(angle) * innerRadius);
    }
    glEnd();

    // Draw inward arrows
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);  // Green arrows
    glLineWidth(2.0f);

    double arrowSize = POWERUP_WIDTH * 0.6 * scaleFactor;
    double arrowHead = POWERUP_WIDTH * 0.2 * scaleFactor;

    // Left arrow
    glBegin(GL_LINES);
    glVertex2d(centerX - arrowSize, centerY);
    glVertex2d(centerX - arrowHead, centerY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(centerX - arrowHead, centerY);
    glVertex2d(centerX - arrowHead * 2, centerY + arrowHead);
    glVertex2d(centerX - arrowHead * 2, centerY - arrowHead);
    glEnd();

    // Right arrow
    glBegin(GL_LINES);
    glVertex2d(centerX + arrowSize, centerY);
    glVertex2d(centerX + arrowHead, centerY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(centerX + arrowHead, centerY);
    glVertex2d(centerX + arrowHead * 2, centerY + arrowHead);
    glVertex2d(centerX + arrowHead * 2, centerY - arrowHead);
    glEnd();
}