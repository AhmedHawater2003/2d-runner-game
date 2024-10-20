#include "Shield.h"
#include <cmath>
#include <glut.h>

// Constructor
Shield::Shield(std::pair<double, double> position)
    : BoundingBox(position, POWERUP_WIDTH, POWERUP_HEIGHT){
}

// Get the shield's position
std::pair<double, double> Shield::getPosition() {
    return position;
}

// Set the shield's position
void Shield::setPosition(std::pair<double, double> position) {
    this->position = position;
}

void Shield::render() {
    // Update the animation time to create a smooth scaling effect
    animationTime += 0.05;

    // Calculate scaling factor using a sine wave for smooth oscillation
    double scaleFactor = 1.0 + 0.5 * std::sin(animationTime);

    // Calculate the center and radius of the shield
    double centerX = position.first + POWERUP_WIDTH / 2;
    double centerY = position.second + POWERUP_HEIGHT / 2;
    double radius = (POWERUP_WIDTH / 2) * scaleFactor;

    // Draw the outer energy ring
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(0.0f, 0.7f, 1.0f, 0.7f);  // Light blue, slightly transparent
    glVertex2d(centerX, centerY);  // Center of circle
    for (int i = 0; i <= 100; ++i) {
        double theta = 2.0 * 3.14159 * double(i) / 100.0;
        double x = centerX + radius * std::cos(theta);
        double y = centerY + radius * std::sin(theta);
        glColor4f(0.0f, 0.7f, 1.0f, 0.1f);  // Fade to transparent at the edge
        glVertex2d(x, y);
    }
    glEnd();

    // NEW: Draw orbiting energy rings
    for (int ring = 0; ring < 3; ring++) {
        glBegin(GL_LINE_STRIP);
        double ringOffset = animationTime * (1.0 + ring * 0.5);
        double ringRadius = radius * (0.6 + ring * 0.2);
        for (int i = 0; i <= 50; ++i) {
            double theta = 2.0 * 3.14159 * double(i) / 50.0 + ringOffset;
            double x = centerX + ringRadius * std::cos(theta);
            double y = centerY + ringRadius * std::sin(theta);
            // Pulse the color
            float alpha = 0.5f + 0.3f * std::sin(animationTime * 2.0 + ring);
            glColor4f(0.3f, 0.8f, 1.0f, alpha);
            glVertex2d(x, y);
        }
        glEnd();
    }

    // Draw hexagonal energy field
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(0.2f, 0.8f, 1.0f, 0.5f);  // Lighter blue, semi-transparent
    for (int i = 0; i < 6; ++i) {
        double theta = 2.0 * 3.14159 * double(i) / 6.0;
        double x = centerX + radius * 0.8 * std::cos(theta);
        double y = centerY + radius * 0.8 * std::sin(theta);
        glVertex2d(x, y);
    }
    glEnd();

    // Draw rotating triangles
    glPushMatrix();
    glTranslated(centerX, centerY, 0);
    glRotated(animationTime * 50, 0, 0, 1);  // Rotate based on animation time
    for (int i = 0; i < 3; ++i) {
        glPushMatrix();
        glRotated(120 * i, 0, 0, 1);
        glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 1.0f, 1.0f, 0.7f);  // Yellow, semi-transparent
        glVertex2d(0, -radius * 0.7);
        glVertex2d(-radius * 0.2, -radius * 0.4);
        glVertex2d(radius * 0.2, -radius * 0.4);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

    // Draw the inner energy core (circle)
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);  // Bright white core
    glVertex2d(centerX, centerY);
    for (int i = 0; i <= 100; ++i) {
        double theta = 2.0 * 3.14159 * double(i) / 100.0;
        double innerRadius = radius * 0.3;  // 30% of the shield's radius
        double x = centerX + innerRadius * std::cos(theta);
        double y = centerY + innerRadius * std::sin(theta);
        glColor4f(0.5f, 0.8f, 1.0f, 0.1f);  // Fade to light blue
        glVertex2d(x, y);
    }
    glEnd();

    // Draw pulsing square
    double squareSize = radius * 0.4 * (1.0 + 0.2 * std::sin(animationTime * 3));
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);  // Green, semi-transparent
    glVertex2d(centerX - squareSize, centerY - squareSize);
    glVertex2d(centerX + squareSize, centerY - squareSize);
    glVertex2d(centerX + squareSize, centerY + squareSize);
    glVertex2d(centerX - squareSize, centerY + squareSize);
    glEnd();
}