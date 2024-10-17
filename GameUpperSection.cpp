#include "GameUpperSection.h"
#include "Text.h"
#include <cmath>
#include <glut.h>

GameUpperSection::GameUpperSection(GameState* gameState, double height) :
	gameState(gameState), height(height) {
	gameTime = new GameTime(50, gameState->getHeight() - (height / 2 + 20), gameState->gameDuration);
	gameScore = new Score(150, gameState->getHeight() - (height / 2 + 20), gameState);
	playerLives = new Lives(250, gameState->getHeight() - (height / 2 + 17), gameState);
    
}
 
void GameUpperSection::render() {

    std::string gameSpeed = "Speed: " + std::to_string(gameState->getSpeed());

    glPushMatrix();

    // Render the player lives, game time, score and game speed on the left
    Text(450, gameState->getHeight() - (height / 2 + 20), gameSpeed).render();
    playerLives->render();
    gameTime->render();
    gameScore->render();


    // Now let's draw a blue sun with solar flares on the right side
    double sunX = gameState->getWidth() - 100; // Position the sun on the right
    double sunY = gameState->getHeight() - 70; // Vertical center of the upper section
    double sunRadius = 30.0; // Size of the sun

    // Sun (Circle) - using GL_TRIANGLE_FAN for the round shape
    glColor3f(0.0f, 0.4f, 1.0f); // Blue sun color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(sunX, sunY); // Center of the sun
    for (int i = 0; i <= 20; ++i) {
        double angle = 2.0 * 3.14 * i / 20;
        double dx = cos(angle) * sunRadius;
        double dy = sin(angle) * sunRadius;
        glVertex2d(sunX + dx, sunY + dy);
    }
    glEnd();

    glColor3f(0.0f, 0.5f, 1.0f); // Lighter blue for solar flares
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 8; ++i) {
        double angle = i * 3.14 / 4; // 45-degree intervals for the flares
        double flareStartX = sunX + cos(angle) * (sunRadius); // Start at sun edge
        double flareStartY = sunY + sin(angle) * (sunRadius);

        double flareMidX = sunX + cos(angle) * (sunRadius + 20); // Mid point of flare, extending out
        double flareMidY = sunY + sin(angle) * (sunRadius + 20);

        double flareEndX = sunX + cos(angle + 3.14 / 16) * (sunRadius + 20); // Slight offset for triangle width
        double flareEndY = sunY + sin(angle + 3.14 / 16) * (sunRadius + 20);

        // Draw the triangle representing each flare
        glVertex2d(flareStartX, flareStartY); // Point on the edge of the sun
        glVertex2d(flareMidX, flareMidY);     // Farther point
        glVertex2d(flareEndX, flareEndY);     // Offset to create triangle width
    }
    glEnd();

    // Inner glow (Ellipse using GL_POLYGON)
    glColor4f(0.0f, 0.2f, 0.8f, 0.6f); // Semi-transparent inner glow
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 20; ++i) {
        double angle = 2.0 * 3.14 * i / 20;
        double dx = cos(angle) * (sunRadius * 0.7);
        double dy = sin(angle) * (sunRadius * 0.7);
        glVertex2d(sunX + dx, sunY + dy);
    }
    glEnd();

    // Sun Border (using GL_LINE_LOOP to add a border around the sun)
    glColor3f(1.0f, 1.0f, 1.0f); // Dark blue border color
    glLineWidth(3.0); // Make the border more visible
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 20; ++i) {
        double angle = 2.0 * 3.14 * i / 20;
        double dx = cos(angle) * sunRadius;
        double dy = sin(angle) * sunRadius;
        glVertex2d(sunX + dx, sunY + dy);
    }
    glEnd();


    glPopMatrix();
}
