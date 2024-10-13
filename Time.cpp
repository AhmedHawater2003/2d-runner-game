#include "Time.h"
#include "Text.h"

Time::Time(double x, double y) : x(x), y(y) {
    startTime = (int)(60*2);
}

void Time::render() {
    std::string time = std::to_string(startTime - (int)(glutGet(GLUT_ELAPSED_TIME) / 1000));
    Text(x, y, "Time: " + time, GLUT_BITMAP_HELVETICA_18).render();
}

