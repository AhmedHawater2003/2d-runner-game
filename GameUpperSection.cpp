#include "GameUpperSection.h"
#include <glut.h>

GameUpperSection::GameUpperSection(GameState* gameState, double height) :
	gameState(gameState), height(height) {
	gameTime = new Time(50, gameState->getHeight() - (height / 2 + 10));
	gameScore = new Score(150, gameState->getHeight() - (height / 2 + 10), gameState);
	playerLives = new Lives(250, gameState->getHeight() - (height / 2 + 10), gameState);
}
 
void GameUpperSection::render() {

	glPushMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(0, gameState->getHeight());
	glVertex2d(gameState->getWidth(), gameState->getHeight());
	glVertex2d(gameState->getWidth(), gameState->getHeight() - height);
	glVertex2d(0, gameState->getHeight() - height);
	glEnd();

	playerLives->render();
	gameTime->render();
	gameScore->render();


	glPopMatrix();
}
