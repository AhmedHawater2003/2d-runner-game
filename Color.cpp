#include "Color.h"
#include <glut.h>

Color::Color(double red, double green, double blue) : red(red), green(green), blue(blue) {}

void Color::apply() {
    glColor3d(red, green, blue);
}

void Color::changeTo(double red, double green, double blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}