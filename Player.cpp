#include "Player.h"
#include <glut.h>

Player::Player(std::pair<double, double> position, double gameLowerBound)
	: BoundingBox(position, ORIGINAL_PLAYER_WIDTH, ORIGINAL_PLAYER_HEIGHT),
	gameLowerBound(gameLowerBound) {
}

void Player::render() {
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2d(position.first, position.second);
	glVertex2d(position.first + width, position.second);
	glVertex2d(position.first + width, position.second + height);
	glVertex2d(position.first, position.second + height);
	glEnd();
}

bool Player::isDucking()
{
	return height == ORIGINAL_PLAYER_HEIGHT /2;
}

void Player::jump()
{
	const double JUMP_HEIGHT = 200;
	if (position.second == gameLowerBound && !isDucking())
		position.second += JUMP_HEIGHT;
}

void Player::duck()
{
	if (position.second == gameLowerBound)
		height = ORIGINAL_PLAYER_HEIGHT / 2;
}

void Player::unDuck()
{
	if (position.second == gameLowerBound)
		height = ORIGINAL_PLAYER_HEIGHT;
}

void Player::applyGravity()
{	
	const double GRAVITY = 5;
	position.second = std::max(gameLowerBound, position.second - GRAVITY);

}
