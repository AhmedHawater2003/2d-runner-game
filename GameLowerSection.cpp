#include "GameLowerSection.h"
#include <glut.h>

GameLowerSection::GameLowerSection(GameState* gameState, double height): gameState(gameState), height(height) {
}

void GameLowerSection::render() {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(gameState->getWidth(), 0);
	glVertex2d(gameState->getWidth(), height);
	glVertex2d(0, height);
	glEnd();

	glPopMatrix();
}
