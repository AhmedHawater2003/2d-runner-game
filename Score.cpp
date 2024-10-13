#include "Score.h"
#include "Text.h"

Score::Score(double x, double y, GameState* gameState) : x(x), y(y), gameState(gameState) {
}

void Score::render() {
	std::string scoreString = std::to_string(gameState->getScore());
	Text(x, y, "Score: " + scoreString, GLUT_BITMAP_HELVETICA_18).render();
}