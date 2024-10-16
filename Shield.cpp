#include "Shield.h"
#include <cmath>
#include <glut.h>

// Constructor
Shield::Shield(std::pair<double, double> position)
    : BoundingBox(position, POWERUP_WIDTH, POWERUP_HEIGHT), animationTime(0.0) {
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
    double scaleFactor = 1.0 + 0.2 * std::sin(animationTime);

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

    // Draw energy waves
    glBegin(GL_LINE_STRIP);
    glColor4f(0.0f, 1.0f, 1.0f, 0.8f);  // Cyan, more opaque
    for (int i = 0; i <= 200; ++i) {
        double theta = 2.0 * 3.14159 * double(i) / 200.0;
        double waveOffset = 0.1 * std::sin(5 * theta + animationTime * 3);
        double x = centerX + (radius * (1 + waveOffset)) * std::cos(theta);
        double y = centerY + (radius * (1 + waveOffset)) * std::sin(theta);
        glVertex2d(x, y);
    }
    glEnd();

    // Draw the inner energy core
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

    // Draw pulsing energy particles
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);  // Bright white particles
    for (int i = 0; i < 50; ++i) {
        double theta = 2.0 * 3.14159 * (double(i) / 50.0 + 0.1 * std::sin(animationTime));
        double particleRadius = radius * (0.5 + 0.5 * std::sin(animationTime * 2 + i));
        double x = centerX + particleRadius * std::cos(theta);
        double y = centerY + particleRadius * std::sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
}
