
#include "Text.h"
#include <glut.h>


Text::Text(double x, double y, std::string text, void* font) : x(x), y(y), text(text), font(font) {}

void Text::render() {
    glColor3f(1, 1, 1);
    glRasterPos2d(x, y);

    for (char& letter : text) {
        glutBitmapCharacter(font, letter);
    }
}