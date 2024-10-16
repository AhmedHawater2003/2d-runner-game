#include "Star.h"
#include <cmath>
#include <utility>
#include <glut.h>

Star::Star(double x, double y, double size)
	: x(x), y(y), size(size), opacity(0), fadeDirection(1.0) {}

void Star::update() {
	opacity += fadeDirection * 0.01; // Adjust fade speed here
	if (opacity > 1.0) {
		opacity = 1.0;
		fadeDirection = -1;
	}
	else if (opacity < 0.0) {
		opacity = 0.0;
		fadeDirection = 1;
	}
}

void Star::render() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set color with the desired opacity
    glColor4f(1.0f, 1.0f, 1.0f, opacity);

    // Number of points on the star
    const int numPoints = 5;

    // Coordinates for the star points (relative to the center)
    double angleStep = 2.0 * 3.14 / numPoints;  // Angle between star points
    double outerRadius = size / 2.0;            // Outer radius of the star
    double innerRadius = outerRadius * 0.5;     // Inner radius (to create the star effect)

    // Start drawing the star using GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);

    // First vertex in the center of the star
    glVertex2d(x, y);

    // Draw the points of the star (alternating between outer and inner radius)
    for (int i = 0; i <= numPoints * 2; ++i) {
        double angle = i * angleStep / 2.0;
        double radius = (i % 2 == 0) ? outerRadius : innerRadius;

        // Calculate the x and y position of each vertex
        double starX = x + radius * cos(angle);
        double starY = y + radius * sin(angle);

        glVertex2d(starX, starY);
    }

    glEnd();
}
