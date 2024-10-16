#include "Obstacle.h"
#include <cmath>
#include <glut.h>

Obstacle::Obstacle(std::pair<double, double> position)
    : BoundingBox(position, OBSTACLE_WIDTH, OBSTACLE_HEIGHT) {
}

std::pair<double, double> Obstacle::getPosition() {
    return position;
}

void Obstacle::setPosition(std::pair<double, double> position) {
    this->position = position;
}

void Obstacle::render() {
    const double centerX = position.first + OBSTACLE_WIDTH / 2;
    const double centerY = position.second + OBSTACLE_HEIGHT / 2;
    const double radius = std::min(OBSTACLE_WIDTH, OBSTACLE_HEIGHT) / 3;  // Approximate ball radius
    const double spikeLength = radius * 0.8;

    // Draw the ball using GL_TRIANGLE_FAN for a smooth circle
    glColor3f(0.7f, 0.2f, 0.2f);  // Dark red
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(centerX, centerY);  // Center of the ball
    for (int i = 0; i <= 360; i += 30) {  // Use 12 segments for the circle
        double angle = i * 3.14 / 180;
        glVertex2d(centerX + radius * cos(angle), centerY + radius * sin(angle));
    }
    glEnd();

    // Draw the spikes (top, bottom, left, right)
    glColor3f(0.9f, 0.1f, 0.1f);  // Bright red
    glBegin(GL_TRIANGLES);

    // Top spike
    glVertex2d(centerX, centerY + radius);  // Top center of the ball
    glVertex2d(centerX - spikeLength / 2, centerY + radius + spikeLength);  // Left of the spike tip
    glVertex2d(centerX + spikeLength / 2, centerY + radius + spikeLength);  // Right of the spike tip

    // Bottom spike
    glVertex2d(centerX, centerY - radius);  // Bottom center of the ball
    glVertex2d(centerX - spikeLength / 2, centerY - radius - spikeLength);  // Left of the spike tip
    glVertex2d(centerX + spikeLength / 2, centerY - radius - spikeLength);  // Right of the spike tip

    // Left spike
    glVertex2d(centerX - radius, centerY);  // Left center of the ball
    glVertex2d(centerX - radius - spikeLength, centerY - spikeLength / 2);  // Bottom of the spike tip
    glVertex2d(centerX - radius - spikeLength, centerY + spikeLength / 2);  // Top of the spike tip

    // Right spike
    glVertex2d(centerX + radius, centerY);  // Right center of the ball
    glVertex2d(centerX + radius + spikeLength, centerY - spikeLength / 2);  // Bottom of the spike tip
    glVertex2d(centerX + radius + spikeLength, centerY + spikeLength / 2);  // Top of the spike tip

    glEnd();
}
