#include "Lives.h"
#include <glut.h>

Lives::Lives(double x, double y, GameState* gameState) : x(x), y(y), gameState(gameState) {
}

void Lives::render() {
    // Get the number of lives left from the game state
    int livesLeft = gameState->getLives();

    // Define the dimensions for the life bar
    double barWidth = 200;   // Full width of the bar
    double barHeight = 20;  // Height of the bar
    double padding = 0;   // Padding between the edges and the bar

    // Calculate the length of the filled portion of the bar based on the number of lives
    double filledBarWidth = (barWidth * livesLeft) / 5.0; // Max lives is 5

    // Render the background (empty bar)
    glColor3f(1, 0.0, 0.0); // Dark red for empty part
    glBegin(GL_QUADS);
    glVertex2f(x, y);                    // Bottom-left corner
    glVertex2f(x + barWidth, y);         // Bottom-right corner
    glVertex2f(x + barWidth, y + barHeight); // Top-right corner
    glVertex2f(x, y + barHeight);        // Top-left corner
    glEnd();

    // Render the filled portion of the bar (lives left)
    glColor3f(0.0, 1, 0.0); // Green for the filled part
    glBegin(GL_QUADS);
    glVertex2f(x + padding, y + padding);                          // Bottom-left (start after padding)
    glVertex2f(x + padding + filledBarWidth - 2 * padding, y + padding);  // Bottom-right (based on lives)
    glVertex2f(x + padding + filledBarWidth - 2 * padding, y + barHeight - padding); // Top-right
    glVertex2f(x + padding, y + barHeight - padding);              // Top-left
    glEnd();

    // Optional: draw a border around the life bar
    glColor3f(1, 1, 1); // Black for border
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + barWidth, y);
    glVertex2f(x + barWidth, y + barHeight);
    glVertex2f(x, y + barHeight);
    glEnd();
}

