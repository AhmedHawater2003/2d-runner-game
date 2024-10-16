#include "Shrink.h"
#include <cmath>
#include <glut.h>

Shrink::Shrink(std::pair<double, double> position)
    : BoundingBox(position, POWERUP_WIDTH, POWERUP_HEIGHT){
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

    // Draw three squares, each smaller than the last
    for (int i = 0; i < 3; ++i) {
        double size = POWERUP_WIDTH * (1.0 - 0.25 * i) * scaleFactor;

        // Alternate colors between purple and magenta
        if (i % 2 == 0) {
            glColor4f(0.5f, 0.0f, 0.5f, 1.0f);  // Purple
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

    // Draw arrows pointing inward
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);  // White arrows
    glLineWidth(3.0f);

    double arrowSize = POWERUP_WIDTH * 0.5 * scaleFactor;
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