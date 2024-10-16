
#include "Text.h"
#include <glut.h>


Text::Text(double x, double y, std::string text,  double red, double green, double blue, void* font) : x(x), y(y), text(text), font(font) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void Text::render() {
    glColor3f(red, green, blue);
    glRasterPos2d(x, y);

    for (char& letter : text) {
        glutBitmapCharacter(font, letter);
    }
}