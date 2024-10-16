#include "Player.h"
#include <cmath>
#include <glut.h>

Player::Player(std::pair<double, double> position, GameState* gameState)
	: BoundingBox(position, ORIGINAL_PLAYER_WIDTH, ORIGINAL_PLAYER_HEIGHT),
	gameState(gameState), shieldingTime(0), shrinkingTime(0) {
}

void Player::render() {
    // scale down with a factor of 2 if shrinking
    scale = shrinkingTime ? 0.6 : 1;

    width = scale * ORIGINAL_PLAYER_WIDTH;
    height = scale * ORIGINAL_PLAYER_HEIGHT / (isDucking() ? 2 : 1);

    const double centerX = position.first + width / 2;
    const double centerY = position.second + height / 2;
    const double radius = std::min(width, height) / 2;  // Approximate ball radius

    glPushMatrix();

    // Head outline (using GL_TRIANGLE_FAN for smooth edges)
    if (shieldingTime)
        glColor4f(0.2f, 0.8f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.8f, 0.2f);  // Bright green

    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(centerX, centerY); // Center of the sun
    for (int i = 0; i <= 20; ++i) {
        double angle = 2.0 * 3.14 * i / 20;
        double dx = cos(angle) * radius;
        double dy = sin(angle) * radius;
        glVertex2d(centerX + dx, centerY + dy);
    }
    glEnd();

    // Eyes (using GL_QUADS for almond shape)
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_QUADS);
    // Left eye
    glVertex2d(position.first + width * 0.25, position.second + height * 0.6);
    glVertex2d(position.first + width * 0.45, position.second + height * 0.7);
    glVertex2d(position.first + width * 0.45, position.second + height * 0.5);
    glVertex2d(position.first + width * 0.25, position.second + height * 0.4);
    // Right eye
    glVertex2d(position.first + width * 0.75, position.second + height * 0.6);
    glVertex2d(position.first + width * 0.55, position.second + height * 0.7);
    glVertex2d(position.first + width * 0.55, position.second + height * 0.5);
    glVertex2d(position.first + width * 0.75, position.second + height * 0.4);
    glEnd();

    // Mouth (using GL_LINE_STRIP)
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_LINE_STRIP);
    glVertex2d(position.first + width * 0.4, position.second + height * 0.25);
    glVertex2d(position.first + width * 0.5, position.second + height * 0.2);
    glVertex2d(position.first + width * 0.6, position.second + height * 0.25);
    glEnd();

    glPopMatrix();
}

bool Player::isDucking()
{
	return height == ORIGINAL_PLAYER_HEIGHT * scale / 2;
}

void Player::jump()
{
	const double JUMP_HEIGHT = 150;
	if (position.second == gameState->getLowerBound() && !isDucking())
		position.second += JUMP_HEIGHT;
}

void Player::duck()
{
	if (position.second == gameState->getLowerBound())
		height = ORIGINAL_PLAYER_HEIGHT * scale / 2;
}

void Player::unDuck()
{
	if (position.second == gameState->getLowerBound())
		height = ORIGINAL_PLAYER_HEIGHT * scale;
}

void Player::applyGravity()
{
	const double MAX_GRAVITY = gameState->maxGravity;   // Maximum gravity strength
	const double MIN_GRAVITY = gameState->minGravity; // Minimum gravity strength when at jump height

	// Calculate the player's height from the lower bound
	double distanceFromGround = position.second - gameState->getLowerBound();

	// Inversely proportional gravity (the closer to the ground, the stronger the gravity)
	// As distance decreases, gravity increases
	// MIN_GRAVITY + (MAX_GRAVITY - MIN_GRAVITY) x factor linearly interpolates between the two gravity strengths
	double gravityStrength = MIN_GRAVITY + (MAX_GRAVITY - MIN_GRAVITY) * (1 - distanceFromGround / 200.0);

	// Apply gravity, ensuring the player doesn't fall below the lower bound
	position.second = std::max(gameState->getLowerBound(), position.second - gravityStrength);
}

void Player::setShieldingTime(int time) {
	shieldingTime = time;
}

void Player::setShrinkingTime(int time) {
	shrinkingTime = time;
}

int Player::getShieldingTime() {
	return shieldingTime;
}

int Player::getShrinkingTime() {
	return shrinkingTime;
}

void Player::decreasePowerUpTime() {
	if (shieldingTime > 0) {
		shieldingTime--;
	}
	if (shrinkingTime > 0) {
		shrinkingTime--;
	}
}