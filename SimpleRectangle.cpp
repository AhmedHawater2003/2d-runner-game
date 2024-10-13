//#include "SimpleRectangle.h"
//#include <glut.h>
//#include <utility>
//
//double SimpleRectangle::GRAVITY = 7;
//
//SimpleRectangle::SimpleRectangle(double x, double y, double width, double height, Color color)
//	: BoundingBox(x, y, width, height), color(color) {}
//
//void SimpleRectangle::render()
//{
//	glPushMatrix();
//	color.apply();
//	glBegin(GL_QUADS);
//	glVertex2d(x, y);
//	glVertex2d(x + width, y);
//	glVertex2d(x + width, y + height);
//	glVertex2d(x, y + height);
//	glEnd();
//	glPopMatrix();
//}
//
//void SimpleRectangle::jump()
//{
//	if(y == 0 && height == 100)
//		y = 300;
//}
//
//void SimpleRectangle::duck()
//{
//	if(y == 0)
//		height = 50;
//}
//
//void SimpleRectangle::infiniteFloat(double speed)
//{	
//	if (x + width - 2 < 0)
//		x = 600;
//	else 
//		x -= speed;
//}
//
//void SimpleRectangle::stretch()
//{
//	height = 100;
//}
//
//void SimpleRectangle::applyGravity()
//{
//	y = std::max(0.0, y-GRAVITY);
//}
//
//void SimpleRectangle::moveX(double x)
//{
//	this->x += x;
//}
//
//void SimpleRectangle::moveY(double y)
//{
//	this->y += y;
//}
//
//void SimpleRectangle::changeColor(double red, double green, double blue)
//{
//	color.changeTo(red, green, blue);
//}