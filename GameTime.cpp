#include "GameTime.h"
#include "Text.h"

GameTime::GameTime(double x, double y, int startTime) : x(x), y(y) {
    this->startTime = startTime;
}

void GameTime::render() {
    std::string time = std::to_string(startTime - (int)(glutGet(GLUT_ELAPSED_TIME) / 1000));
    Text(x, y, "Time: " + time).render();
}

